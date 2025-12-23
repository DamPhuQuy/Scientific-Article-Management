#include "articleupdatedialog.h"
#include "src/utils/datautils.h"
#include "ui_articleupdatedialog.h"

#include "src/models/conference_article.h"
#include "src/models/scie_article.h"
#include "src/models/scopus_article.h"

ArticleUpdateDialog::ArticleUpdateDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleUpdateDialog)
    , repo(repo)
{
    ui->setupUi(this);
}

ArticleUpdateDialog::~ArticleUpdateDialog()
{
    delete ui;
}

void ArticleUpdateDialog::loadData(Article* article) {
    currentArticle = article;

    ui->editTitle->setPlainText(QString::fromStdString(currentArticle->getTitle()));
    ui->editVenue->setText(QString::fromStdString(currentArticle->getVenue()));
    ui->spinYear->setValue(currentArticle->getYear());
    ui->spinCitation->setValue(currentArticle->getCitation());
    ui->editAbstract->setPlainText(QString::fromStdString(currentArticle->getAbstract()));

    switch(currentArticle->getType()) {
    case Type::SCIE:
        ui->comboType->setCurrentIndex(0);
        ui->stackInputs->setCurrentWidget(ui->pageInputSCIE);
        if (auto *s = dynamic_cast<SCIE_Article*>(article)) {
            ui->spinIF->setValue(s->getImpactFactor());
            ui->spinQRank->setValue((s->getQRank()));
        }
        break;
    case Type::SCOPUS:
        ui->comboType->setCurrentIndex(1);
        ui->stackInputs->setCurrentWidget(ui->pageInputSCOPUS);
        if (auto* s = dynamic_cast<SCOPUS_Article*>(article)) {
            ui->spinSJR->setValue(s->getSJR());
            ui->spinHIndex->setValue(s->getHIndex());
        }
        break;
    case Type::CONFERENCE:
        ui->comboType->setCurrentIndex(2);
        ui->stackInputs->setCurrentWidget(ui->pageInputSCOPUS);
        if (auto* s = dynamic_cast<CONFERENCE_Article*>(article)) {
            ui->editConfRank->setText(QString::fromStdString(s->getRank()));
            ui->editLocation->setText(QString::fromStdString((s->getLocation())));
            ui->spinAcceptRate->setValue(s->getAcceptanceRate());
        }
        break;
    case Type::OTHER: break;
    default:
        ui->comboType->setCurrentIndex(3);
        ui->stackInputs->setCurrentWidget(ui->pageInputOTHER);
        break;
    }

    ui->comboStatus->setCurrentIndex(static_cast<int>(article->getStatus()) - 11);

    QString authorsText;
    for(const auto& auth : article->getAuthors()) {
        authorsText += QString::fromStdString(auth) + "\n";
    }
    ui->editAuthors->setPlainText(authorsText.trimmed());

    QString refsText;
    for(const auto& r : article->getReferences()) {
        refsText += QString::fromStdString(r) + "\n";
    }
    ui->editRefs->setPlainText(refsText.trimmed());
}

void ArticleUpdateDialog::on_saveBtn_clicked()
{
    if (!currentArticle) return;

    if (currentArticle) {
        currentArticle->setTitle(ui->editTitle->toPlainText().toStdString());
        currentArticle->setVenue(ui->editVenue->text().toStdString());
        currentArticle->setYear(ui->spinYear->value());
        currentArticle->setCitation(ui->spinCitation->value());
        currentArticle->setAbstract(ui->editAbstract->toPlainText().toStdString());

        currentArticle->setStatus(static_cast<ArticleStatus>(ui->comboStatus->currentIndex() + 11));
    }

    auto parseListFromText = [](const QString& text) -> vector<string> {
        vector<string> list;
        unordered_set<string> seen;
        QStringList lines = text.split('\n', Qt::SkipEmptyParts);
        for (const QString& line : lines) {
            if (seen.find(line.trimmed().toStdString()) != seen.end()) {
                continue;
            }
            list.push_back(line.trimmed().toStdString());
            seen.insert(line.trimmed().toStdString());
        }
        return list;
    };

    currentArticle->setAuthors(parseListFromText(ui->editAuthors->toPlainText()));
    currentArticle->setRefs(parseListFromText(ui->editRefs->toPlainText()));

    switch (currentArticle->getType()) {
    case Type::SCIE:
        if (auto* s = dynamic_cast<SCIE_Article*>(currentArticle)) {
            s->setImpactFactor(ui->spinIF->value());
            s->setQRank(ui->spinQRank->value());
        }
        break;

    case Type::SCOPUS:
        if (auto* s = dynamic_cast<SCOPUS_Article*>(currentArticle)) {
            s->setSJR(ui->spinSJR->value());
            s->setHIndex(ui->spinHIndex->value());
        }
        break;

    case Type::CONFERENCE:
        if (auto* s = dynamic_cast<CONFERENCE_Article*>(currentArticle)) {
            s->setRank(ui->editConfRank->text().toStdString());
            s->setLocation(ui->editLocation->text().toStdString());
            s->setAcceptanceRate(ui->spinAcceptRate->value());
        }
        break;

    case Type::OTHER:
        break;
    case Type::CUSTOM:
        break;
    }

    repo.getArticles().update(DataUtils::createArticle(currentArticle));
    accept();
}


void ArticleUpdateDialog::on_closeBtn_clicked()
{
    reject();
}

