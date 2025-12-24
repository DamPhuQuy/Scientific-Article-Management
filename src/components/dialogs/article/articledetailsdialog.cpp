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
#include "src/components/dialogs/article/articleconfirmremovedialog.h"
#include "src/utils/usermanager.h"
#include "src/utils/constants.h"
#include <set>
#include <fstream>
#include <QListWidgetItem>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QStringConverter>
#include <QDateTime>
#include "src/utils/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

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
    ui->lblVenue->setText(QString::fromStdString("Publication Venue: " + currentArticle->getVenue()));
    ui->lblYear->setText(QString::number(currentArticle->getYear()));
    ui->lblCitation->setText(QString::number(currentArticle->getCitation()) + " citations");
    ui->txtAbstract->setText(QString::fromStdString(currentArticle->getAbstract()));

    // Hide update and remove buttons if user is not Admin
    QString userRole = repo.getUsers().getRole(QString::fromStdString(currentUsername));
    bool isAdmin = (userRole == "Admin");

    qDebug() << "Current username:" << QString::fromStdString(currentUsername);
    qDebug() << "User role:" << userRole;
    qDebug() << "Is admin:" << isAdmin;

    ui->btnUpdate->setVisible(isAdmin);
    ui->removeBtn->setVisible(isAdmin);

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
        case Type::OTHER: ui->typeBox->setCurrentIndex(3); break;
        case Type::CUSTOM: {
            // Tìm index của custom type trong combobox
            CUSTOM_Article* customArticle = dynamic_cast<CUSTOM_Article*>(currentArticle);
            if (customArticle) {
                QString customTypeName = QString::fromStdString(customArticle->getCustomTypeName());
                int index = ui->typeBox->findText(customTypeName);
                if (index != -1) {
                    ui->typeBox->setCurrentIndex(index);
                } else {
                    ui->typeBox->setCurrentIndex(4); // fallback
                }
            }
            break;
        }
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
    } else if (auto* custom = dynamic_cast<CUSTOM_Article*>(currentArticle)) {
        qDebug() << "Run-time type: CUSTOM -" << custom->getCustomTypeName();
        ui->stackedSpecificInfo->setCurrentWidget(ui->pageCUSTOM);
        ui->valCustomTypeName->setText(QString::fromStdString(custom->getCustomTypeName()));
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
        std::string articleId = currentArticle->getId();
        currentArticle = repo.getArticles().findById(articleId).get();
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
    std::string key = repo.getUsers().getKeyManipulation(currentUsername);
    removeDialog.setExpectedKey(key);

    if (removeDialog.exec() == QDialog::Accepted) {
        repo.getArticles().remove(currentArticle->getId());
        repo.getArticles().save();
        accept(); // Close details dialog
    }
}

void ArticleDetailsDialog::on_listAuthors_itemDoubleClicked(QListWidgetItem *item)
{
    if (!item) return;

    // Get author ID from item data
    QString authorId = item->data(Qt::UserRole).toString();

    // Find author in repository
    Author author = repo.getAuthors().findById(authorId.toStdString());

    if (author.getId().empty()) {
        return; // Author not found
    }

    // Open author details dialog
    AuthorDetailsDialog authorDialog(repo, this);
    authorDialog.setAuthorInfo(
        QString::fromStdString(author.getId()),
        QString::fromStdString(author.getFullName()),
        QString::fromStdString(author.getCountry()),
        QString::fromStdString(author.getFieldOfStudy()),
        author.getTotalPublications()
    );

    authorDialog.exec();
}

void ArticleDetailsDialog::exportToCSV() {
    if (!currentArticle) {
        QMessageBox::warning(this, "Thiếu dữ liệu", "Không có bài báo để export.");
        return;
    }

    QString baseDir = QString::fromStdString(EXPORT_FOLDER);
    if (baseDir.isEmpty()) {
        baseDir = "exported";
    }

    QDir rootDir(baseDir);
    if (!rootDir.exists() && !rootDir.mkpath(".")) {
        QMessageBox::warning(this, "Error", "Cannot create root export folder.");
        return;
    }

    QString userFolderName = QString::fromStdString(currentUsername);
    QDir userDir(rootDir.filePath(userFolderName));
    if (!userDir.exists() && !userDir.mkpath(".")) {
        QMessageBox::warning(this, "Error", "Cannot create export folder for account.");
        return;
    }

    QString filePath = userDir.filePath(QString::fromStdString(currentArticle->getId()) + ".csv");

    if (QFile::exists(filePath)) {
        QMessageBox::information(this, "Already Exported", "This article has been exported before at:\n" + filePath);
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file for writing: " + filePath);
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    auto quote = [](const QString& value) {
        QString escaped = value;
        escaped.replace("\"", "\"\"");
        return "\"" + escaped + "\"";
    };

    QStringList authorsList;
    for (const auto& authorId : currentArticle->getAuthors()) {
        Author author = repo.getAuthors().findById(authorId);
        if (!author.getFullName().empty()) {
            authorsList << QString::fromStdString(author.getFullName());
        }
    }

    QStringList refsList;
    for (const auto& ref : currentArticle->getReferences()) {
        refsList << QString::fromStdString(ref);
    }

    out << "Field,Value\n";
    out << "ID," << quote(QString::fromStdString(currentArticle->getId())) << "\n";
    out << "Title," << quote(QString::fromStdString(currentArticle->getTitle())) << "\n";
    out << "Venue," << quote(QString::fromStdString(currentArticle->getVenue())) << "\n";
    out << "Year," << currentArticle->getYear() << "\n";
    out << "Citations," << currentArticle->getCitation() << "\n";
    out << "Type," << quote(QString::fromStdString(currentArticle->typeToString(currentArticle->getType()))) << "\n";
    out << "Status," << quote(QString::fromStdString(currentArticle->getStatusInString())) << "\n";
    out << "Abstract," << quote(QString::fromStdString(currentArticle->getAbstract())) << "\n";
    out << "Authors," << quote(authorsList.join("; ")) << "\n";
    out << "References," << quote(refsList.join("; ")) << "\n";

    if (auto scie = dynamic_cast<SCIE_Article*>(currentArticle)) {
        out << "Impact Factor," << scie->getImpactFactor() << "\n";
        out << "Q Rank," << scie->getQRank() << "\n";
    } else if (auto scopus = dynamic_cast<SCOPUS_Article*>(currentArticle)) {
        out << "SJR," << scopus->getSJR() << "\n";
        out << "H-Index," << scopus->getHIndex() << "\n";
    } else if (auto conf = dynamic_cast<CONFERENCE_Article*>(currentArticle)) {
        out << "Conference Rank," << quote(QString::fromStdString(conf->getRank())) << "\n";
        out << "Location," << quote(QString::fromStdString(conf->getLocation())) << "\n";
        out << "Acceptance Rate," << conf->getAcceptanceRate() << "\n";
    } else if (auto custom = dynamic_cast<CUSTOM_Article*>(currentArticle)) {
        out << "Custom Type," << quote(QString::fromStdString(custom->getCustomTypeName())) << "\n";
    }

    file.close();

    QMessageBox::information(this, "Success", "CSV exported to:\n" + filePath);
}

void ArticleDetailsDialog::exportToJSON() {
    if (!currentArticle) {
        QMessageBox::warning(this, "Thiếu dữ liệu", "Không có bài báo để export.");
        return;
    }

    QString baseDir = QString::fromStdString(EXPORT_FOLDER);
    if (baseDir.isEmpty()) {
        baseDir = "exported";
    }

    QDir rootDir(baseDir);
    if (!rootDir.exists() && !rootDir.mkpath(".")) {
        QMessageBox::warning(this, "Error", "Cannot create root export folder.");
        return;
    }

    QString userFolderName = QString::fromStdString(currentUsername.empty() ? "guest" : currentUsername);
    QDir userDir(rootDir.filePath(userFolderName));
    if (!userDir.exists() && !userDir.mkpath(".")) {
        QMessageBox::warning(this, "Error", "Cannot create export folder for account.");
        return;
    }

    QString filePath = userDir.filePath(QString::fromStdString(currentArticle->getId()) + ".json");

    if (QFile::exists(filePath)) {
        QMessageBox::information(this, "Already Exported", "This article has been exported before at:\n" + filePath);
        return;
    }

    nlohmann::json doc = currentArticle->to_json();
    doc["exported_by"] = currentUsername;
    doc["exported_at"] = QDateTime::currentDateTime().toString(Qt::ISODate).toStdString();

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file for writing: " + filePath);
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << QString::fromStdString(doc.dump(4));

    file.close();

    QMessageBox::information(this, "Success", "JSON exported to:\n" + filePath);
}

void ArticleDetailsDialog::on_btnExport_clicked()
{
    if (!currentArticle) {
        QMessageBox::warning(this, "Missing Data", "No article to export.");
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Export Article");
    msgBox.setText("Select export format for the article.");
    auto csvBtn = msgBox.addButton("CSV", QMessageBox::AcceptRole);
    auto jsonBtn = msgBox.addButton("JSON", QMessageBox::AcceptRole);
    msgBox.addButton(QMessageBox::Cancel);

    msgBox.exec();

    if (msgBox.clickedButton() == csvBtn) {
        exportToCSV();
    } else if (msgBox.clickedButton() == jsonBtn) {
        exportToJSON();
    }
}