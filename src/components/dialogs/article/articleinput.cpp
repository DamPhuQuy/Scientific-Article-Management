#include "articleinput.h"
#include "ui_articleinput.h"

ArticleInput::ArticleInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleInput)
{
    ui->setupUi(this);
}

ArticleInput::~ArticleInput()
{
    delete ui;
}
