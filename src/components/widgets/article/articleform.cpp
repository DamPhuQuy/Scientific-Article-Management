#include "articleform.h"
#include "ui_articleform.h"
#include "src/components/dialogs/article/articleinputdialog.h"
#include "src/components/dialogs/article/articledetailsdialog.h"
#include "src/components/dialogs/user/userdetailsdialog.h"
#include "src/utils/usermanager.h"
#include "src/models/customarticle.h"
#include "src/components/dialogs/article/articlestatistics.h"
#include <set>

ArticleForm::ArticleForm(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , repo(repo)
    , ui(new Ui::ArticleForm)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->articleListView->setModel(model);

    initData();
    loadArticlesToView();

    ui->articleListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->articleListView->setFlow(QListView::TopToBottom);

    updateTypeComboBox();
}

ArticleForm::~ArticleForm()
{
    delete ui;
}

void ArticleForm::updateUIAfterLogin() {
    qDebug() << currentUser.first << currentUser.second;

    ui->userLb->setText(currentUser.first);
    qDebug() << "Set label to:" << currentUser.first << "| Actual label:" << ui->userLb->text();

    ui->RemoveArticleBtn->setVisible(currentUser.second == "Admin");
}

void ArticleForm::setCurrentUser(const std::pair<QString, QString>& user) {
    currentUser = user;
}

void ArticleForm::on_newArticleBtn_clicked()
{
    ArticleInputDialog inputDialog(repo, this);

    if (inputDialog.exec() == QDialog::Accepted) {
        articleList.clear();

        // reload data and show the view again
        initData();

        loadArticlesToView();

        updateTypeComboBox();

        applyAllFilters();
    }
}

void ArticleForm::on_RemoveArticleBtn_clicked()
{
    // ArticleRemoveDialog removeDialog(repo, this);

    // removeDialog.exec();
}

void ArticleForm::on_backBtn_clicked()
{
    emit requestBack();
}

void ArticleForm::initData() {
    articleList.clear();
    articleList.reserve(repo.getArticles().getContainer().size());
    repo.getArticles().getContainer().forEach([&](const shared_ptr<Article>& article) {
        articleList.push_back(article);
    });
}

void ArticleForm::loadArticlesToView() {
    model->clear();

    for (const auto& article : articleList) {
        QStandardItem *item = new QStandardItem(QString::fromStdString((article->getTitle())));

        item->setData(QString::fromStdString(article->getId()), Qt::UserRole);

        const int year = article->getYear();
        QString typeStr = QString::fromStdString(article->typeToString(article->getType()));
        if (article->getType() == Type::CUSTOM) {
            if (auto *custom = dynamic_cast<CUSTOM_Article*>(article.get())) {
                typeStr = QString::fromStdString(custom->getCustomTypeName());
            }
        }

        QString abstract = QString::fromStdString(article->getAbstract());
        if (abstract.length() > 100) {
            abstract = abstract.left(100) + "...";
        }

        item->setText(QString("%1 | Year: %2 | Type: %3")
                  .arg(QString::fromStdString(article->getTitle()))
                  .arg(year)
                  .arg(typeStr));

        QFont font = item->font();
        font.setPointSize(font.pointSize() - 1);
        item->setFont(font);
        QColor grayColor(128, 128, 128);
        item->setForeground(QBrush(grayColor));

        item->setText(item->text() + "\n" + abstract);

        item->setToolTip(QString("Title: %1\nYear: %2\nType: %3")
                             .arg(QString::fromStdString(article->getTitle()))
                             .arg(year)
                             .arg(typeStr));

        model->appendRow(item);
    }
}

void ArticleForm::on_articleListView_doubleClicked(const QModelIndex &index) {
    string articleId = index.data(Qt::UserRole).toString().toStdString();

    Article* selectedArticle;
    bool found = false;
    for(const auto& ar : articleList) {
        if(ar->getId() == articleId) {
            selectedArticle = ar.get();
            found = true;
            break;
        }
    }

    if (!found) return;

    ArticleDetailsDialog detailDlg(repo, this);

    detailDlg.setArticleData(
        selectedArticle
    );
    detailDlg.setCurrentUsername(currentUser.first.toStdString());

    if (detailDlg.exec() == QDialog::Accepted) {
        initData();

        qDebug() << articleList.size();

        loadArticlesToView();

        updateTypeComboBox();

        applyAllFilters();
    }
}

void ArticleForm::on_searchLineEdit_textChanged(const QString &arg1)
{
    filterTitle = arg1.trimmed();
    applyAllFilters();
}

void ArticleForm::on_yearFilterComboBox_currentTextChanged(const QString &arg1)
{
    this->filterYear = (arg1 == "All Years") ? QString() : arg1;
    applyYearSorting();
}

void ArticleForm::on_typeFilterComboBox_currentTextChanged(const QString &arg1)
{
    this->filterType = (arg1 == "All Types") ? QString() : arg1;
    applyAllFilters();
}

bool ArticleForm::passesAllFilters(int row) const { // check with each row (each elements)
    // fetch item
    QStandardItem *item = model->item(row, 0);
    if (item == nullptr) {
        return false; // no data
    }

    // fetch hidden id from item
    QString currentId = item->data(Qt::UserRole).toString();

    shared_ptr<Article> foundArticle = nullptr;
    bool isFound = false;

    for (const auto &ar : articleList) {
        if (QString::fromStdString(ar->getId()) == currentId) {
            foundArticle = ar;
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        return false;
    }

    // data to filter
    QString title = QString::fromStdString(foundArticle->getTitle());
    QString type = QString::fromStdString(foundArticle->typeToString(foundArticle->getType()));

    // line search
    if (!filterTitle.isEmpty()) {
        if (!title.contains(filterTitle, Qt::CaseInsensitive)) {
            return false;
        }
    }

    // field
    if (!filterType.isEmpty() && filterType != "All Types") {
        if (foundArticle->getType() == Type::CUSTOM) {
             CUSTOM_Article* customArticle = dynamic_cast<CUSTOM_Article*>(foundArticle.get());
             if (customArticle) {
                 if (QString::fromStdString(customArticle->getCustomTypeName()) != filterType) {
                     return false;
                 }
             } else {
                 return false;
             }
        } else {
            if (type != filterType) {
                return false;
            }
        }
    }

    return true;
}

void ArticleForm::applyYearSorting() {
    if (filterYear == "Newest First") {
        // desc
        std::sort(articleList.begin(), articleList.end(),
                  [](const std::shared_ptr<Article>& a, const std::shared_ptr<Article>& b) {
                      return a->getYear() > b->getYear();
                  });
    }
    else if (filterYear == "Oldest First") {
        // asc
        std::sort(articleList.begin(), articleList.end(),
                  [](const std::shared_ptr<Article>& a, const std::shared_ptr<Article>& b) {
                      return a->getYear() < b->getYear();
                  });
    }

    // load data again
    loadArticlesToView();

    applyAllFilters();
}

void ArticleForm::applyAllFilters() { // apply to all rows of element
    if (!model) return;
    for (int row = 0; row < model->rowCount(); ++row) {
        bool isVisible = passesAllFilters(row);

        ui->articleListView->setRowHidden(row, !isVisible);
    }
}

void ArticleForm::on_userLb_clicked()
{
    UserDetailsDialog userdialog(repo, this);

    QString username = currentUser.first;

    userdialog.setUserInfo(
        username,
        UserManager::getFullName(username),
        UserManager::getEmail(username),
        UserManager::getPhone(username),
        UserManager::getRole(username),
        UserManager::getKeyManipulation(username)
    );

    userdialog.exec();
}

void ArticleForm::updateTypeComboBox() {
    ui->typeFilterComboBox->clear();
    ui->typeFilterComboBox->addItem("All Types");
    ui->typeFilterComboBox->addItem("SCIE");
    ui->typeFilterComboBox->addItem("SCOPUS");
    ui->typeFilterComboBox->addItem("CONFERENCE");
    ui->typeFilterComboBox->addItem("OTHER");

    std::set<std::string> customTypes;
    repo.getArticles().getContainer().forEach([&](const shared_ptr<Article>& article) {
        if (article->getType() == Type::CUSTOM) {
            CUSTOM_Article* customArticle = dynamic_cast<CUSTOM_Article*>(article.get());
            if (customArticle) {
                customTypes.insert(customArticle->getCustomTypeName());
            }
        }
    });

    for (const auto& typeName : customTypes) {
        ui->typeFilterComboBox->addItem(QString::fromStdString(typeName));
    }
}

void ArticleForm::on_pushButton_clicked()
{
    ArticleStatistics statsDialog(repo, this);
    statsDialog.exec();
}

