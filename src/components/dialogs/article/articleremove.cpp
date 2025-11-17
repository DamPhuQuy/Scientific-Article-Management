#include "articleremove.h"
#include "ui_articleremove.h"

ArticleRemove::ArticleRemove(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleRemove)
{
    ui->setupUi(this);
}

ArticleRemove::~ArticleRemove()
{
    delete ui;
}
