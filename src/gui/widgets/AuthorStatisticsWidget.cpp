#include "AuthorStatisticsWidget.h"
#include "ui_AuthorStatisticsWidget.h" // Header được sinh tự động từ file .ui

AuthorStatisticsWidget::AuthorStatisticsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorStatisticsWidget)
{
    ui->setupUi(this); // Tải và thiết lập giao diện từ file .ui

    //--- Kết nối các nút bấm với tín hiệu của widget ---

    connect(ui->statsByCountryButton, &QPushButton::clicked,
            this, &AuthorStatisticsWidget::statsByCountryRequested);

    connect(ui->statsByFieldButton, &QPushButton::clicked,
            this, &AuthorStatisticsWidget::statsByFieldRequested);

    connect(ui->topAuthorsButton, &QPushButton::clicked,
            this, &AuthorStatisticsWidget::topAuthorsRequested);

    // Nút "Back" sẽ phát tín hiệu backClicked
    connect(ui->backButton, &QPushButton::clicked,
            this, &AuthorStatisticsWidget::backClicked);
}

AuthorStatisticsWidget::~AuthorStatisticsWidget()
{
    delete ui;
}