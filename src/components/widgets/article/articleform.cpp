#include "articleform.h"
#include "ui_articleform.h"

ArticleForm::ArticleForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ArticleForm)
{
    ui->setupUi(this);
}

ArticleForm::~ArticleForm()
{
    delete ui;
}
