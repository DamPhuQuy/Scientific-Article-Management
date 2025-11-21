#include "userdetailsdialog.h"
#include "ui_userdetailsdialog.h"

UserDetailsDialog::UserDetailsDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserDetailsDialog)
    , repo(repo)
{
    ui->setupUi(this);
}

UserDetailsDialog::~UserDetailsDialog()
{
    delete ui;
}

void UserDetailsDialog::setUserInfo(QString username, QString fullname, QString email, QString phoneNumber)
{
    ui->labelDetailUsername->setText(username);
    ui->labelDetailFullname->setText(fullname);
    ui->labelDetailEmail->setText(email);
    ui->labelDetailPhoneNumber->setText(phoneNumber);
}

void UserDetailsDialog::on_okBtn_clicked()
{
    accept();
}

