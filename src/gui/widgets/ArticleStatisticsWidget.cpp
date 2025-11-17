#include "ArticleStatisticsWidget.h"
#include "ui_ArticleStatisticsWidget.h" // Header được sinh tự động từ file .ui

ArticleStatisticsWidget::ArticleStatisticsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleStatisticsWidget)
{
    ui->setupUi(this); // Tải và thiết lập giao diện từ file .ui

    //--- Kết nối các nút bấm với tín hiệu của widget ---

    connect(ui->statsByYearButton, &QPushButton::clicked,
            this, &ArticleStatisticsWidget::statsByYearRequested);

    connect(ui->statsByTypeButton, &QPushButton::clicked,
            this, &ArticleStatisticsWidget::statsByTypeRequested);

    // Nút "Back" sẽ phát tín hiệu backClicked
    connect(ui->backButton, &QPushButton::clicked,
            this, &ArticleStatisticsWidget::backClicked);
}

ArticleStatisticsWidget::~ArticleStatisticsWidget()
{
    delete ui;
}