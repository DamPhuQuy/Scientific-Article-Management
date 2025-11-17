#include "authordescription.h"
#include "ui_authordescription.h"

AuthorDescription::AuthorDescription(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorDescription)
{
    ui->setupUi(this);
}

AuthorDescription::~AuthorDescription()
{
    delete ui;
}
