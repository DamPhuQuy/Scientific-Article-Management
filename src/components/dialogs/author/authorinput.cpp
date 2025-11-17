#include "authorinput.h"
#include "ui_authorinput.h"

AuthorInput::AuthorInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorInput)
{
    ui->setupUi(this);
}

AuthorInput::~AuthorInput()
{
    delete ui;
}
