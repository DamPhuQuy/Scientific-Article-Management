#include "signupform.h"
#include "ui_signupform.h"

SignUpForm::SignUpForm(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , repo(repo)
    , ui(new Ui::SignUpForm)
{
    ui->setupUi(this);
}

SignUpForm::~SignUpForm()
{
    delete ui;
}
