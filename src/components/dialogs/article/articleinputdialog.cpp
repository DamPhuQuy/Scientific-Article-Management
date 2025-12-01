#include "articleinputdialog.h"
#include "ui_articleinputdialog.h"
#include <QFormLayout>
#include "src/components/dialogs/msg/inform.h"
#include "src/utils/datautils.h"
#include "src/components/dialogs/author/listofauthorsdialog.h"

ArticleInputDialog::ArticleInputDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleInputDialog)
    , repo(repo)
{
    ui->setupUi(this);

    this->username = "";

    // Add CUSTOM type
    ui->inputType->addItem("CUSTOM");

    // Create page for CUSTOM type
    QWidget* pageCustom = new QWidget();
    QFormLayout* layoutCustom = new QFormLayout(pageCustom);
    inputCustomTypeName = new QLineEdit(pageCustom);
    layoutCustom->addRow("Custom Type Name:", inputCustomTypeName);
    ui->stackType->addWidget(pageCustom);

    connect(ui->inputType, SIGNAL(currentIndexChanged(int)),
            ui->stackType, SLOT(setCurrentIndex(int)));

    ui->stackType->setCurrentIndex(ui->inputType->currentIndex());
}

ArticleInputDialog::~ArticleInputDialog()
{
    delete ui;
}

void ArticleInputDialog::on_btnSave_clicked()
{
    if (ui->inputTitle->text().trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập title", "Lỗi");
        return;
    }
    if (ui->inputVenue->text().trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập venue", "Lỗi");
        return;
    }

    QString title = ui->inputTitle->text();
    QString abstract = ui->inputAbstract->toPlainText();
    QString venue = ui->inputVenue->text();

    // inputYear is a QComboBox, so we get the text and convert to int
    int year = ui->inputYear->currentText().toInt();

    int n_citation = ui->inputCitations->value();

    ArticleStatus status;
    int statusIndex = ui->inputStatus->currentIndex();
    switch (statusIndex) {
        case 0: status = ArticleStatus::DRAFT; break;
        case 1: status = ArticleStatus::SUBMITTED; break;
        case 2: status = ArticleStatus::UNDER_REVIEW; break;
        case 3: status = ArticleStatus::REVISIONS; break;
        case 4: status = ArticleStatus::ACCEPTED; break;
        case 5: status = ArticleStatus::REJECTED; break;
        case 6: status = ArticleStatus::PUBLISHED; break;
        default: status = ArticleStatus::DRAFT; break;
    }

    QString refsText = ui->inputRefs->toPlainText();
    QStringList refList = refsText.split('\n', Qt::SkipEmptyParts);
    vector<string> refs;
    refs.reserve(refList.size());
    for (const QString &line : refList) {
        refs.push_back(line.trimmed().toStdString());
    }

    Type type;
    int typeIndex = ui->inputType->currentIndex();

    double impactFactor = 0.0;
    int qRank = 0;
    double sjr = 0.0;
    int hIndex = 0;
    QString confRank = "";
    QString location = "";
    double acceptRate = 0.0;
    QString customTypeName = "";

    switch (typeIndex) {
    case 0: // SCIE
        type = Type::SCIE;
        impactFactor = ui->inputIF->value();
        qRank = ui->inputQRank->value();
        qDebug() << "Type: SCIE | IF:" << impactFactor << "| Q:" << qRank;
        break;

    case 1: // SCOPUS
        type = Type::SCOPUS;
        sjr = ui->inputSJR->value();
        hIndex = ui->inputHIndex->value();
        qDebug() << "Type: SCOPUS | SJR:" << sjr << "| H-Index:" << hIndex;
        break;

    case 2: // CONFERENCE
        type = Type::CONFERENCE;
        confRank = ui->inputConfRank->text();
        location = ui->inputLocation->text();
        acceptRate = ui->inputAcceptRate->value();
        qDebug() << "Type: CONFERENCE |ed Rank:" << confRank << "| Loc:" << location;
        break;

    case 3: // OTHER
        type = Type::OTHER;
        qDebug() << "Type: OTHER";
        break;

    case 4: // CUSTOM
        type = Type::CUSTOM;
        customTypeName = inputCustomTypeName->text().trimmed();
        if (customTypeName.isEmpty()) {
            Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập tên loại bài báo tùy chỉnh", "Lỗi");
            return;
        }
        qDebug() << "Type: CUSTOM | Name:" << customTypeName;
        break;
    }

    if (m_selectedAuthorIds.empty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng chọn ít nhất một tác giả!", "Thiếu thông tin");
        return;
    }

    unique_ptr<Article> article = DataUtils::createArticle(
        abstract.toStdString(),
        n_citation,
        title.toStdString(),
        venue.toStdString(),
        year,
        "",
        type,
        status,
        refs,
        m_selectedAuthorIds,
        confRank.toStdString(),
        location.toStdString(),
        acceptRate,
        impactFactor,
        qRank,
        sjr,
        hIndex,
        customTypeName.toStdString()
    );

    repo.getArticles().save(std::move(article));

    qDebug() << "Saved Article:" << title << "Year:" << year;
    accept();
}


void ArticleInputDialog::on_btnCancel_clicked()
{
    reject();
}


void ArticleInputDialog::on_inputType_currentIndexChanged(int index)
{
    ui->stackType->setCurrentIndex(index);
}

void ArticleInputDialog::setCurrentUser(const QString& username)
{
    this->username = username;
}

void ArticleInputDialog::on_AuthorBtn_clicked()
{
    ListOfAuthorsDialog authorDialog(repo, this);
    authorDialog.setCurrentUser(username);

    if (authorDialog.exec() == QDialog::Accepted) {

        m_selectedAuthorIds = authorDialog.getSelectedAuthorIds();

        if (m_selectedAuthorIds.empty()) {
            ui->AuthorBtn->setText("Chọn tác giả (Chưa chọn ai)");
        } else {
            QString label = QString("Đã chọn %1 tác giả").arg(m_selectedAuthorIds.size());
            ui->AuthorBtn->setText(label);
        }

        // Debug log để kiểm tra
        qDebug() << "Selected Authors Count:" << m_selectedAuthorIds.size();
    }
}
