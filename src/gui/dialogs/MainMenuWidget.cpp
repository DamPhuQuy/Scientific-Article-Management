#include "MainMenuWidget.h"
#include "ui_MainMenuWidget.h" // Header được sinh tự động từ MainMenuWidget.ui

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this); // Tải và thiết lập giao diện từ file .ui

    //--- Kết nối các nút bấm với tín hiệu của widget ---

    // Khi nút 'manageArticlesButton' (trong file .ui) được nhấn,
    // widget 'MainMenuWidget' này sẽ phát ra tín hiệu 'manageArticlesClicked()'
    connect(ui->manageArticlesButton, &QPushButton::clicked,
            this, &MainMenuWidget::manageArticlesClicked);

    // Tương tự cho nút "Manage Authors"
    connect(ui->manageAuthorsButton, &QPushButton::clicked,
            this, &MainMenuWidget::manageAuthorsClicked);

    // Tương tự cho nút "Exit"
    connect(ui->exitButton, &QPushButton::clicked,
            this, &MainMenuWidget::exitClicked);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}