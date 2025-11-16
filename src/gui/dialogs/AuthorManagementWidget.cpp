#include "AuthorManagementWidget.h"
#include "ui_AuthorManagementWidget.h" // Header được sinh tự động từ file .ui

AuthorManagementWidget::AuthorManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorManagementWidget)
{
    ui->setupUi(this); // Tải và thiết lập giao diện từ file .ui

    //--- Kết nối các nút bấm với tín hiệu của widget ---

    connect(ui->createAuthorButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::createAuthorRequested);

    connect(ui->viewAllAuthorsButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::viewAllAuthorsRequested);

    connect(ui->updateAuthorButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::updateAuthorRequested);

    connect(ui->deleteAuthorButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::deleteAuthorRequested);

    connect(ui->searchAuthorsButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::searchAuthorsRequested);

    connect(ui->statisticsButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::showStatisticsRequested);

    connect(ui->backButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::backToMainMenuRequested);
}

AuthorManagementWidget::~AuthorManagementWidget()
{
    delete ui;
}