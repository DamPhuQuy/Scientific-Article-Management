#include "articledescription.h"
#include "ui_articledescription.h"

ArticleDescription::ArticleDescription(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleDescription)
{
    ui->setupUi(this);
}

ArticleDescription::~ArticleDescription()
{
    delete ui;
}
