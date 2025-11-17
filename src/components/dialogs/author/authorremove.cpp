#include "authorremove.h"
#include "ui_authorremove.h"

AuthorRemove::AuthorRemove(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorRemove)
{
    ui->setupUi(this);
}

AuthorRemove::~AuthorRemove()
{
    delete ui;
}
