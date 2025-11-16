#include "ArticleManagementWidget.h"
#include "ui_ArticleManagementWidget.h" // Header được sinh tự động từ file .ui

ArticleManagementWidget::ArticleManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleManagementWidget)
{
    ui->setupUi(this); // Tải và thiết lập giao diện từ file .ui

    //--- Kết nối các nút bấm với tín hiệu của widget ---

    connect(ui->createArticleButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::createArticleRequested);

    connect(ui->viewAllArticlesButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::viewAllArticlesRequested);

    connect(ui->updateArticleButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::updateArticleRequested);

    connect(ui->deleteArticleButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::deleteArticleRequested);

    connect(ui->searchArticlesButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::searchArticlesRequested);

    connect(ui->statisticsButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::showStatisticsRequested);

    connect(ui->backButton, &QPushButton::clicked,
            this, &ArticleManagementWidget::backToMainMenuRequested);
}

ArticleManagementWidget::~ArticleManagementWidget()
{
    delete ui;
}