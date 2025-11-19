#include "articleupdate.h"
#include "ui_articleupdate.h"

ArticleUpdate::ArticleUpdate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleUpdate)
{
    ui->setupUi(this);
}

ArticleUpdate::~ArticleUpdate()
{
    delete ui;
}

void ArticleUpdate::on_btnCancel_clicked()
{
    emit requestBack();
}


void ArticleUpdate::on_btnUpdate_clicked()
{
    // update

    emit updateSuccess;
}

