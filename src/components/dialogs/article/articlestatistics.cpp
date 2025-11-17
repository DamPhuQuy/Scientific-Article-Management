#include "articlestatistics.h"
#include "ui_articlestatistics.h"

ArticleStatistics::ArticleStatistics(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleStatistics)
{
    ui->setupUi(this);
}

ArticleStatistics::~ArticleStatistics()
{
    delete ui;
}
