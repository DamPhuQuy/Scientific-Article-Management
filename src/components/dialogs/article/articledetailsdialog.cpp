#include "articledetailsdialog.h"
#include "ui_articledetailsdialog.h"

#include "src/components/dialogs/article/articleupdatedialog.h"
#include "src/components/dialogs/author/authordetailsdialog.h"
#include "src/repos/repomanager.h"
#include "src/models/article.h"
#include "src/models/scie_article.h"
#include "src/models/conference_article.h"
#include "src/models/scopus_article.h"
#include "src/models/other_article.h"
#include "src/models/customarticle.h"
#include <QDebug>
#include <set>

using namespace std;

ArticleDetailsDialog::ArticleDetailsDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleDetailsDialog)
    , repo(repo)
{
    ui->setupUi(this);

    ui->statusBox->setEnabled(false);
    ui->typeBox->setEnabled(false);

    set<string> customTypes;
    repo.getArticles().getContainer().forEach([&](const shared_ptr<Article>& article) {
        if (article->getType() == Type::CUSTOM) {
            CUSTOM_Article* customArticle = dynamic_cast<CUSTOM_Article*>(article.get());
            if (customArticle) {
                customTypes.insert(customArticle->getCustomTypeName());
            }
        }
    });

    for (const auto& typeName : customTypes) {
        ui->typeBox->addItem(QString::fromStdString(typeName));
    }
}

ArticleDetailsDialog::~ArticleDetailsDialog()
{
    delete ui;
}

void ArticleDetailsDialog::setArticleData(Article* article) {
    this->currentArticle = article;

    ui->lblTitle->setText(QString::fromStdString(currentArticle->getTitle()));
    ui->lblId->setText("ID: " + QString::fromStdString(currentArticle->getId()));
    ui->lblVenue->setText(QString::fromStdString("Venue: " + currentArticle->getVenue()));
    ui->lblYear->setText(QString::number(currentArticle->getYear()));
    ui->lblCitation->setText(QString::number(currentArticle->getCitation()) + " Citations");
    ui->txtAbstract->setText(QString::fromStdString(currentArticle->getAbstract()));

    ui->listAuthors->clear();
    for (const auto& authorId : currentArticle->getAuthors()) {
        // Look up the author by ID to get the name
        Author authorObj = repo.getAuthors().findById(authorId);
        
        QString displayName;
        if (!authorObj.getId().empty()) {
            displayName = QString::fromStdString(authorObj.getFullName());
        } else {
            // Fallback to ID if author not found (though it should be)
            displayName = QString::fromStdString(authorId);
        }

        QListWidgetItem* item = new QListWidgetItem(displayName);
        // Store the ID in UserRole for easy retrieval
        item->setData(Qt::UserRole, QString::fromStdString(authorId));
        ui->listAuthors->addItem(item);
    }

    ui->listRefs->clear();
    for (const auto& ref : currentArticle->getReferences()) {
        ui->listRefs->addItem(QString::fromStdString(ref));
    }

    switch (currentArticle->getType()) {
        case Type::SCIE: ui->typeBox->setCurrentIndex(0); break;
        case Type::SCOPUS: ui->typeBox->setCurrentIndex(1); break;
        case Type::CONFERENCE: ui->typeBox->setCurrentIndex(2); break;
        case Type::CUSTOM: ui->typeBox->setCurrentIndex(4); break;
        default: ui->typeBox->setCurrentIndex(3); break;
    }

    switch (currentArticle->getStatus()) {
        case ArticleStatus::DRAFT: ui->statusBox->setCurrentIndex(0); break;
        case ArticleStatus::SUBMITTED: ui->statusBox->setCurrentIndex(1); break;
        case ArticleStatus::UNDER_REVIEW: ui->statusBox->setCurrentIndex(2); break;
        case ArticleStatus::REVISIONS: ui->statusBox->setCurrentIndex(3); break;
        case ArticleStatus::ACCEPTED: ui->statusBox->setCurrentIndex(4); break;
        case ArticleStatus::REJECTED: ui->statusBox->setCurrentIndex(5); break;
        case ArticleStatus::PUBLISHED: ui->statusBox->setCurrentIndex(6); break;
    }

        qDebug()
            << "SCIE:" << (dynamic_cast<SCIE_Article*>(currentArticle) != nullptr)
            << "SCOPUS:" << (dynamic_cast<SCOPUS_Article*>(currentArticle) != nullptr)
            << "CONF:" << (dynamic_cast<CONFERENCE_Article*>(currentArticle) != nullptr)
            << "OTHER:" << (dynamic_cast<OTHER_Article*>(currentArticle) != nullptr);


    if (auto* scie = dynamic_cast<SCIE_Article*>(currentArticle)) {
        qDebug() << "Run-time type:" << typeid(*currentArticle).name();
        ui->stackedSpecificInfo->setCurrentWidget(ui->pageSCIE);

        ui->valIF->setText(QString::number(scie->getImpactFactor(), 'f', 2));
        ui->valQRank->setText("Q" + QString::number(scie->getQRank()));
    }
    else if (auto* scopus = dynamic_cast<SCOPUS_Article*>(currentArticle)) {
        qDebug() << "Run-time type:" << typeid(*currentArticle).name();
        ui->stackedSpecificInfo->setCurrentWidget(ui->pageSCOPUS);

        ui->valSJR->setText(QString::number(scopus->getSJR(), 'f', 2));
        ui->valHIndex->setText(QString::number(scopus->getHIndex()));
    }
    else if (auto* conf = dynamic_cast<CONFERENCE_Article*>(currentArticle)) {
        qDebug() << "Run-time type:" << typeid(*currentArticle).name();
        ui->stackedSpecificInfo->setCurrentWidget(ui->pageCONF);

        ui->valConfRank->setText(QString::fromStdString(conf->getRank()));
        ui->valLocation->setText(QString::fromStdString(conf->getLocation()));
        ui->valAcceptRate->setText(QString::number(conf->getAcceptanceRate()) + "%");
    }
    else {
        ui->stackedSpecificInfo->setCurrentWidget(ui->pageOTHER);
    }
}

void ArticleDetailsDialog::on_btnUpdate_clicked()
{
    if (!currentArticle) return;
    auto articlePtr = repo.getArticles().findById(currentArticle->getId());
    if (!articlePtr) {
        qDebug() << "[ERROR] Không tìm thấy article!";
        return;
    }

    ArticleUpdateDialog updateDialog(repo, this);
    updateDialog.setCurrentArticle(articlePtr.get());
    updateDialog.loadData(articlePtr.get());
    
    if (updateDialog.exec() == QDialog::Accepted) {
        setArticleData(currentArticle);
    }
}

void ArticleDetailsDialog::on_listAuthors_itemDoubleClicked(QListWidgetItem *item)
{
    if (!item) return;
    
    // Retrieve the ID stored in UserRole
    QString authorId = item->data(Qt::UserRole).toString();
    
    // Find author by ID
    Author author = repo.getAuthors().findById(authorId.toStdString());
    
    if (!author.getId().empty()) {
        AuthorDetailsDialog authorDlg(repo, this);
        authorDlg.setAuthorInfo(
            QString::fromStdString(author.getId()),
            QString::fromStdString(author.getFullName()),
            QString::fromStdString(author.getCountry()),
            QString::fromStdString(author.getFieldOfStudy()),
            author.getTotalPublications()
        );
        authorDlg.exec();
    } else {
        // Optional: Show a message if author not found in database
        // Inform::showMessage(this, MessageType::Info, "Author details not found.", "Info");
        qDebug() << "Author not found in database with ID: " << authorId;
    }
}


void ArticleDetailsDialog::on_closeBtn_clicked()
{
    reject();
}

