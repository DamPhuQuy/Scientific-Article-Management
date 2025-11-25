#include "articleupdatedialog.h"
#include "ui_articleupdatedialog.h"
#include <QFormLayout>
#include "src/utils/datautils.h"
#include "src/components/dialogs/msg/inform.h"  // fix Inform + MessageType

#include "src/models/conference_article.h"
#include "src/models/scie_article.h"
#include "src/models/scopus_article.h"

#include <QRegularExpression>

ArticleUpdateDialog::ArticleUpdateDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleUpdateDialog)
    , repo(repo)
{
    ui->setupUi(this);

    connect(ui->saveBtn, &QPushButton::clicked, this, &ArticleUpdateDialog::on_saveBtn_clicked);
    connect(ui->closeBtn, &QPushButton::clicked, this, &ArticleUpdateDialog::on_closeBtn_clicked);
}

ArticleUpdateDialog::~ArticleUpdateDialog()
{
    delete ui;
}

void ArticleUpdateDialog::on_saveBtn_clicked()
{
    try {
        qDebug() << "[DEBUG] on_saveBtn_clicked started";
        if (!currentArticle) {
            qDebug() << "[ERROR] Save clicked but currentArticle is NULL!";
            return;
        }

        // --- Lấy dữ liệu từ UI ---
        QString qtitle = ui->editTitle->toPlainText().trimmed();
        if (qtitle.isEmpty()) {
            Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập title", "Lỗi");
            return;
        }

        QString qvenue = ui->editVenue->text().trimmed();
        if (qvenue.isEmpty()) {
            Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập venue", "Lỗi");
            return;
        }

        int year = ui->spinYear->value();
        int citation = ui->spinCitation->value();
        QString qabstract = ui->editAbstract->toPlainText().trimmed();

        // --- Authors ---
        QStringList authorLines = ui->editAuthors->toPlainText().split(QRegularExpression("[\r\n]"), Qt::SkipEmptyParts);
        std::vector<std::string> authorsVec;
        authorsVec.reserve(authorLines.size());
        for (const QString &a : authorLines) authorsVec.push_back(a.trimmed().toStdString());

        // --- References ---
        QStringList refsLines = ui->editRefs->toPlainText().split(QRegularExpression("[\r\n]"), Qt::SkipEmptyParts);
        std::vector<std::string> refsVec;
        refsVec.reserve(refsLines.size());
        for (const QString &r : refsLines) refsVec.push_back(r.trimmed().toStdString());

        qDebug() << "[DEBUG] Updating base article fields";
        // --- Cập nhật dữ liệu cho Article ---
        currentArticle->setTitle(qtitle.toStdString());
        currentArticle->setVenue(qvenue.toStdString());
        currentArticle->setYear(year);
        currentArticle->setCitation(citation);
        currentArticle->setAbstract(qabstract.toStdString());
        
        // Fix: Pass status as string because Article::setStatus(any) doesn't handle ArticleStatus enum directly
        currentArticle->setStatus(ui->comboStatus->currentText().toStdString());
        
        currentArticle->setAuthors(authorsVec);
        currentArticle->setRefs(refsVec);

        qDebug() << "[DEBUG] Updating type-specific fields";
        // --- Type-specific fields ---
        Type t = currentArticle->getType();
        switch (t) {
            case Type::SCIE: {
                auto *s = dynamic_cast<SCIE_Article*>(currentArticle);
                if (s) {
                    s->setImpactFactor(ui->spinIF->value());
                    s->setQRank(ui->spinQRank->value());
                }
                break;
            }
            case Type::SCOPUS: {
                auto *s = dynamic_cast<SCOPUS_Article*>(currentArticle);
                if (s) {
                    s->setSJR(ui->spinSJR->value());
                    s->setHIndex(ui->spinHIndex->value());
                }
                break;
            }
            case Type::CONFERENCE: {
                auto *c = dynamic_cast<CONFERENCE_Article*>(currentArticle);
                if (c) {
                    c->setRank(ui->editConfRank->text().toStdString());
                    c->setLocation(ui->editLocation->text().toStdString());
                    c->setAcceptanceRate(ui->spinAcceptRate->value());
                }
                break;
            }
            default:
                break;
        }

        qDebug() << "[DEBUG] Calling repo.save()";
        // --- Lưu Article vào Repo ---
        repo.getArticles().save();

        qDebug() << "[INFO] Article updated and saved: " << QString::fromStdString(currentArticle->getTitle());

        accept(); // đóng dialog
    } catch (const std::exception& e) {
        qCritical() << "[CRITICAL] Exception in on_saveBtn_clicked: " << e.what();
        Inform::showMessage(this, MessageType::Warning, QString("Lỗi khi lưu: %1").arg(e.what()), "Lỗi");
    } catch (...) {
        qCritical() << "[CRITICAL] Unknown exception in on_saveBtn_clicked";
        Inform::showMessage(this, MessageType::Warning, "Lỗi không xác định khi lưu", "Lỗi");
    }
}

void ArticleUpdateDialog::loadData(Article* article) {
    qDebug() << "[DEBUG] ArticleUpdateDialog::loadData called with article:" << (article ? QString::fromStdString(article->getId()) : "NULL");
    if (!article) return;
    currentArticle = article;

    qDebug() << "[DEBUG] Setting common fields";
    ui->editTitle->setPlainText(QString::fromStdString(article->getTitle()));
    ui->editVenue->setText(QString::fromStdString(article->getVenue()));
    ui->spinYear->setValue(article->getYear());
    ui->spinCitation->setValue(article->getCitation());
    ui->editAbstract->setPlainText(QString::fromStdString(article->getAbstract()));

    // Status
    int statusIndex = static_cast<int>(article->getStatus()) - 11;
    if (statusIndex >= 0 && statusIndex < ui->comboStatus->count()) {
        ui->comboStatus->setCurrentIndex(statusIndex);
    }

    // Authors
    QString authorsStr;
    for (const auto& a : article->getAuthors()) {
        authorsStr += QString::fromStdString(a) + "\n";
    }
    ui->editAuthors->setPlainText(authorsStr.trimmed());

    // Refs
    QString refsStr;
    for (const auto& r : article->getReferences()) {
        refsStr += QString::fromStdString(r) + "\n";
    }
    ui->editRefs->setPlainText(refsStr.trimmed());

    qDebug() << "[DEBUG] Checking type specific fields";
    // Type specific
    if (auto* s = dynamic_cast<SCIE_Article*>(article)) {
        qDebug() << "[DEBUG] Loading SCIE data";
        ui->spinIF->setValue(s->getImpactFactor());
        ui->spinQRank->setValue(s->getQRank());
        ui->stackInputs->setCurrentWidget(ui->pageInputSCIE);
        ui->comboType->setCurrentIndex(0);
    } else if (auto* s = dynamic_cast<SCOPUS_Article*>(article)) {
        qDebug() << "[DEBUG] Loading SCOPUS data";
        ui->spinSJR->setValue(s->getSJR());
        ui->spinHIndex->setValue(s->getHIndex());
        ui->stackInputs->setCurrentWidget(ui->pageInputSCOPUS);
        ui->comboType->setCurrentIndex(1);
    } else if (auto* c = dynamic_cast<CONFERENCE_Article*>(article)) {
        qDebug() << "[DEBUG] Loading CONFERENCE data";
        ui->editConfRank->setText(QString::fromStdString(c->getRank()));
        ui->editLocation->setText(QString::fromStdString(c->getLocation()));
        ui->spinAcceptRate->setValue(c->getAcceptanceRate());
        ui->stackInputs->setCurrentWidget(ui->pageInputCONF);
        ui->comboType->setCurrentIndex(2);
    } else {
        qDebug() << "[DEBUG] Loading OTHER data";
        ui->stackInputs->setCurrentWidget(ui->pageInputOTHER);
        ui->comboType->setCurrentIndex(3);
    }
    qDebug() << "[DEBUG] loadData finished";
}


void ArticleUpdateDialog::on_closeBtn_clicked()
{
    reject();
}
