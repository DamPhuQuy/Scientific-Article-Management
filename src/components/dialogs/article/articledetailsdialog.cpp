#include "articledetailsdialog.h"
#include "ui_articledetailsdialog.h"

#include "src/components/dialogs/article/articleupdatedialog.h"
#include "src/repos/repomanager.h"
#include "src/models/article.h"
#include "src/models/scie_article.h"
#include "src/models/conference_article.h"
#include "src/models/scopus_article.h"
#include "src/models/other_article.h"
#include "src/models/customarticle.h"
#include "src/components/dialogs/article/articleconfirmremovedialog.h"
#include "src/utils/usermanager.h"
#include <set>
#include <QListWidgetItem>

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
        Author author = repo.getAuthors().findById(authorId);
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(author.getFullName()));
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
    ArticleUpdateDialog updateDialog(repo, this);
    updateDialog.loadData(currentArticle);

    if (updateDialog.exec() == QDialog::Accepted) {
        setArticleData(currentArticle);
        dataChanged = true;
    }
}


void ArticleDetailsDialog::on_closeBtn_clicked()
{
    done(dataChanged ? QDialog::Accepted : QDialog::Rejected);
}


void ArticleDetailsDialog::on_removeBtn_clicked()
{
    ArticleConfirmRemoveDialog removeDialog(repo, this);

    // Get key manipulation from current user
    std::string key = UserManager::getKeyManipulation(currentUsername);
    removeDialog.setExpectedKey(key);

    if (removeDialog.exec() == QDialog::Accepted) {
        repo.getArticles().remove(currentArticle->getId());
        repo.getArticles().save();
        accept(); // Close details dialog
    }
}

