#include "authorupdate.h"
#include "ui_authorupdate.h"

AuthorUpdate::AuthorUpdate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorUpdate)
{
    ui->setupUi(this);
}

AuthorUpdate::~AuthorUpdate()
{
    delete ui;
}
