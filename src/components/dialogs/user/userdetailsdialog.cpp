#include "userdetailsdialog.h"
#include "ui_userdetailsdialog.h"
#include "src/components/dialogs/user/userupdateinfo.h"
#include "src/utils/usermanager.h"

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

void UserDetailsDialog::setUserInfo(QString username, QString fullname, QString email, QString phoneNumber, QString role, QString key)
{
    ui->labelDetailUsername->setText(username);
    ui->labelDetailFullname->setText(fullname);
    ui->labelDetailEmail->setText(email);
    ui->labelDetailPhoneNumber->setText(phoneNumber);
    ui->labelDetailRole->setText(role);
    ui->labelDetailKey->setText(key);
}

void UserDetailsDialog::on_okBtn_clicked()
{
    accept();
}

void UserDetailsDialog::on_btnUpdate_clicked()
{
    QString username = ui->labelDetailUsername->text();
    QString fullname = ui->labelDetailFullname->text();
    QString email = ui->labelDetailEmail->text();
    QString phone = ui->labelDetailPhoneNumber->text();

    userUpdateInfo updateDialog(repo, this);
    updateDialog.loadUserInfo(username, fullname, email, phone);
    if (updateDialog.exec() == QDialog::Accepted) {
        // Reload user info
        setUserInfo(
            username,
            UserManager::getFullName(username),
            UserManager::getEmail(username),
            UserManager::getPhone(username),
            UserManager::getRole(username),
            UserManager::getKeyManipulation(username)
        );
    }
}

