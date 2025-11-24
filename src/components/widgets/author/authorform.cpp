#include "authorform.h"
#include "ui_authorform.h"

AuthorForm::AuthorForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthorForm)
{
    ui->setupUi(this);
}

AuthorForm::~AuthorForm()
{
    delete ui;
}
