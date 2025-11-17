#include "AuthorManagementWidget.h"
#include "ui_AuthorManagementWidget.h"

AuthorManagementWidget::AuthorManagementWidget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::AuthorManagementWidget)
{
    ui->setupUi(this);

    connect(ui->createAuthorButton,  &QPushButton::clicked,
            this, &AuthorManagementWidget::createAuthorRequested);

    connect(ui->viewAllAuthorsButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::viewAllAuthorsRequested);

    connect(ui->updateAuthorButton,  &QPushButton::clicked,
            this, &AuthorManagementWidget::updateAuthorRequested);

    connect(ui->deleteAuthorButton,  &QPushButton::clicked,
            this, &AuthorManagementWidget::deleteAuthorRequested);

    connect(ui->searchAuthorsButton, &QPushButton::clicked,
            this, &AuthorManagementWidget::searchAuthorsRequested);

    connect(ui->statisticsButton,    &QPushButton::clicked,
            this, &AuthorManagementWidget::showStatisticsRequested);

    connect(ui->backButton,          &QPushButton::clicked,
            this, &AuthorManagementWidget::backToMainMenuRequested);
}

AuthorManagementWidget::~AuthorManagementWidget()
{
    delete ui;
}
