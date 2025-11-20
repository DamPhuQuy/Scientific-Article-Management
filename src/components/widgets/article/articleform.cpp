#include "articleform.h"
#include "ui_articleform.h"
#include "src/components/dialogs/article/articleinputdialog.h"
#include "src/components/dialogs/article/articledetailsdialog.h"

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
}

ArticleForm::~ArticleForm()
{
    delete ui;
}

void ArticleForm::on_newArticleBtn_clicked()
{
    ArticleInputDialog inputDialog(repo, this);

    inputDialog.exec();
}

void ArticleForm::on_RemoveArticleBtn_clicked()
{
    emit openArticleRemoveArticleDialog();
}


void ArticleForm::on_searchBtn_clicked()
{

}


void ArticleForm::on_backBtn_clicked()
{
    emit requestBack();
}

void ArticleForm::initData() {
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

    detailDlg.exec();
}
