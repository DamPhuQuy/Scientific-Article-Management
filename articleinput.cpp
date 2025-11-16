#include "articleinput.h"
#include "ui_articleinput.h"

#include <QDialog>
#include <QInputDialog>
#include "./src/repos/repomanager.h"
#include "./src/utils/datautils.h"
#include "articlemenu.h"
#include <QString>
#include <qgraphicseffect.h>

ArticleInput::ArticleInput(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainDialog), repo(repo)
{
    ui->setupUi(this);

    setupSignals();
}

ArticleInput::~ArticleInput()
{
    delete ui;
}

void ArticleInput::setupSignals()
{
    connect(ui->addArticleButton, &QPushButton::clicked, this, [this]() -> void {
        QString title = ui->titleLineEdit->text();
        QString venue = ui->venueLineEdit->text();
        int year = ui->yearSpin->value();
        int nCitations = ui->citationSpin->value();
        QString abstractText = ui->abstractTextEdit->toPlainText();

        // Thu thập authors (ID)
        vector<string> authors;
        for (int i = 0; i < ui->authorsListWidget->count(); ++i) {
            authors.push_back(ui->authorsListWidget->item(i)->text().toStdString());
        }

        // Thu thập references
        vector<string> references;
        for (int i = 0; i < ui->referencesListWidget->count(); ++i) {
            references.push_back(ui->referencesListWidget->item(i)->text().toStdString());
        }

        // Loại bài báo
        Type type;
        QString typeStr = ui->typeComboBox->currentText();
        if (typeStr == "SCIE") type = Type::SCIE;
        else if (typeStr == "CONFERENCE") type = Type::CONFERENCE;
        else if (typeStr == "SCOPUS") type = Type::SCOPUS;
        else type = Type::OTHER;

        // Status
        ArticleStatus status;
        QString statusStr = ui->statusComboBox->currentText();
        if (statusStr == "DRAFT") status = ArticleStatus::DRAFT;
        else if (statusStr == "PUBLISHED") status = ArticleStatus::PUBLISHED;
        else if (statusStr == "UNDER_REVIEW") status = ArticleStatus::UNDER_REVIEW;
        else if (statusStr == "ACCEPTED") status = ArticleStatus::ACCEPTED;
        else if (statusStr == "REJECTED") status = ArticleStatus::REJECTED;
        else if (statusStr == "SUBMITTED") status = ArticleStatus::SUBMITTED;
        else if (statusStr == "REVISIONS") status = ArticleStatus::REVISIONS;

        // Type-specific fields
        QString conferenceRank = ui->conferenceRankLineEdit->text();
        QString location = ui->locationLineEdit->text();
        double acceptanceRate = ui->acceptanceRateSpinBox->value();
        double impactFactor = ui->impactFactorSpinBox->value();
        int qRank = ui->qRankSpinBox->value();
        double sjr = ui->sjrSpinBox->value();
        int hIndex = ui->hIndexSpinBox->value();

        // Tạo article
        auto article = DataUtils::createArticle(
            abstractText.toStdString(),
            nCitations,
            title.toStdString(),
            venue.toStdString(),
            year,
            "",
            type,
            status,
            references,
            authors,
            conferenceRank.toStdString(),
            location.toStdString(),
            acceptanceRate,
            impactFactor,
            qRank,
            sjr,
            hIndex
            );

        // Gửi vào repo
        repo.getArticles().add(std::move(article));
    });

    connect(ui->cancelButton, &QPushButton::clicked, this, &ArticleInput::backToMenu);
}

void ArticleInput::applyStyles()
{
    // 1. Background cho mainDialog
    this->setStyleSheet(R"(
        /* Main Dialog Background */
        #mainDialog {
            background: url(:/images/background.png) cente  r center no-repeat;
            border-radius: 20px;
        }

        /* Central Card Styling */
        #centralCard {
            background: rgba(255, 255, 255, 0.88);
            border-radius: 20px;
            border: 1px solid rgba(0, 0, 0, 0.05);
        }

        /* Shadow Effect cho Card */
        #centralCard {
            background: rgba(255, 255, 255, 0.95);
            border-radius: 20px;
            border: 1px solid rgba(0, 0, 0, 0.08);
        }

        /* Typography - Tiêu đề */
        #titleLabel {
            font-size: 24px;
            font-weight: bold;
            color: #1a1a1a;
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        #subtitleLabel {
            font-size: 14px;
            color: #666666;
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        /* Group Labels */
        #detailsGroupLabel, #abstractLabel, #authorsLabel, #referencesLabel {
            font-size: 16px;
            font-weight: bold;
            color: #333333;
            font-family: 'Segoe UI', Arial, sans-serif;
            padding-bottom: 4px;
            border-bottom: 1px solid rgba(0, 0, 0, 0.1);
        }

        /* Input Fields - QLineEdit */
        QLineEdit {
            background: rgba(255, 255, 255, 0.9);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 12px 16px;
            font-size: 14px;
            color: #333333;
            font-family: 'Segoe UI', Arial, sans-serif;
            min-height: 20px;
        }

        QLineEdit:focus {
            border: 2px solid #007AFF;
            background: rgba(255, 255, 255, 1);
        }

        QLineEdit::placeholder {
            color: #999999;
            font-style: italic;
        }

        /* QSpinBox và QDoubleSpinBox */
        QSpinBox, QDoubleSpinBox {
            background: rgba(255, 255, 255, 0.9);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 8px 12px;
            font-size: 14px;
            color: #333333;
            min-height: 20px;
        }

        QSpinBox:focus, QDoubleSpinBox:focus {
            border: 2px solid #007AFF;
        }

        /* QComboBox */
        QComboBox {
            background: rgba(255, 255, 255, 0.9);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 10px 12px;
            font-size: 14px;
            color: #333333;
            min-height: 20px;
        }

        QComboBox:focus {
            border: 2px solid #007AFF;
        }

        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 25px;
            border-left: 1px solid rgba(0, 0, 0, 0.1);
            border-top-right-radius: 10px;
            border-bottom-right-radius: 10px;
        }

        QComboBox::down-arrow {
            image: none;
            border-left: 4px solid transparent;
            border-right: 4px solid transparent;
            border-top: 4px solid #666666;
            width: 0px;
            height: 0px;
        }

        QComboBox QAbstractItemView {
            background: white;
            border: 1px solid rgba(0, 0, 0, 0.1);
            border-radius: 8px;
            padding: 4px;
            font-size: 13px;
            selection-background-color: #007AFF;
            selection-color: white;
        }

        QComboBox QAbstractItemView::item {
            padding: 8px 12px;
            border-radius: 4px;
            margin: 2px;
        }

        QComboBox QAbstractItemView::item:hover {
            background: #F0F0F0;
        }

        /* QTextEdit */
        QTextEdit {
            background: rgba(255, 255, 255, 0.9);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 12px 16px;
            font-size: 14px;
            color: #333333;
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        QTextEdit:focus {
            border: 2px solid #007AFF;
            background: rgba(255, 255, 255, 1);
        }

        QTextEdit::placeholder {
            color: #999999;
            font-style: italic;
        }

        /* QListWidget */
        QListWidget {
            background: rgba(255, 255, 255, 0.9);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 4px;
            font-size: 14px;
            color: #333333;
            outline: none;
        }

        QListWidget:focus {
            border: 2px solid #007AFF;
        }

        QListWidget::item {
            padding: 8px 12px;
            border-radius: 6px;
            margin: 2px;
        }

        QListWidget::item:hover {
            background: #F0F0F0;
        }

        QListWidget::item:selected {
            background: #007AFF;
            color: white;
        }

        /* Buttons */
        #cancelButton {
            background: rgba(0, 0, 0, 0.05);
            border: 2px solid rgba(0, 0, 0, 0.1);
            border-radius: 12px;
            padding: 12px 24px;
            font-size: 14px;
            font-weight: bold;
            color: #333333;
            min-height: 48px;
        }

        #cancelButton:hover {
            background: rgba(0, 0, 0, 0.08);
            border: 2px solid rgba(0, 0, 0, 0.15);
        }

        #cancelButton:pressed {
            background: rgba(0, 0, 0, 0.12);
        }

        #addArticleButton {
            background: #000000;
            border: 2px solid #000000;
            border-radius: 12px;
            padding: 12px 24px;
            font-size: 14px;
            font-weight: bold;
            color: white;
            min-height: 48px;
        }

        #addArticleButton:hover {
            background: #333333;
            border: 2px solid #333333;
        }

        #addArticleButton:pressed {
            background: #111111;
            border: 2px solid #111111;
        }

        /* Labels trong form */
        QLabel {
            color: #333333;
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        /* ScrollArea */
        QScrollArea {
            background: transparent;
            border: none;
        }

        QScrollBar:vertical {
            background: rgba(0, 0, 0, 0.05);
            width: 10px;
            border-radius: 5px;
        }

        QScrollBar::handle:vertical {
            background: rgba(0, 0, 0, 0.2);
            border-radius: 5px;
            min-height: 20px;
        }

        QScrollBar::handle:vertical:hover {
            background: rgba(0, 0, 0, 0.3);
        }

        /* Stacked Widget Pages */
        QWidget#page_scie, QWidget#page_conference,
        QWidget#page_scopus, QWidget#page_other {
            background: rgba(248, 249, 250, 0.5);
            border: 1px solid rgba(0, 0, 0, 0.08);
            border-radius: 8px;
            padding: 8px;
        }
    )");

    // Thêm shadow effect cho centralCard (cần làm trong code)
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(30);
    shadowEffect->setColor(QColor(0, 0, 0, 80));
    shadowEffect->setOffset(0, 0);
    ui->centralCard->setGraphicsEffect(shadowEffect);

    // Đặt font cho application
    QFont appFont("Segoe UI", 10);
    qApp->setFont(appFont);
}
