#include "userupdateinfo.h"
#include "ui_userupdateinfo.h"
#include "src/components/dialogs/msg/inform.h"
#include "src/utils/usermanager.h"

userUpdateInfo::userUpdateInfo(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userUpdateInfo)
    , repo(repo)
{
    ui->setupUi(this);
}

userUpdateInfo::~userUpdateInfo()
{
    delete ui;
}

void userUpdateInfo::setUsername(QString username) {
    m_username = username;
}

void userUpdateInfo::loadUserInfo(QString username, QString fullname, QString email, QString phone) {
    m_username = username;
    ui->txtUsername->setText(username);
    ui->txtFullname->setText(fullname);
    ui->txtEmail->setText(email);
    ui->txtPhone->setText(phone);
}

void userUpdateInfo::on_btnCancel_clicked() {
    reject();
}

void userUpdateInfo::on_btnSave_clicked()
{
    QString fullname = ui->txtFullname->text();
    QString email = ui->txtEmail->text();
    QString phone = ui->txtPhone->text();

    // Update basic info
    UserManager::updateUserInfo(m_username, fullname, email, phone);

    QString old = ui->txtOldPass->text();
    QString newP = ui->txtNewPass->text();
    QString confirm = ui->txtConfirmPass->text();

    if (!newP.isEmpty()) {
        if (newP != confirm) {
            // TODO: Show error message "Password confirm does not match"
            Inform::showMessage(this, MessageType::Warning, "Password is different!", "Update Error");
            return;
        }

        UserManager::changePassword(m_username.toStdString(), newP.toStdString());
        Inform::showMessage(this, MessageType::Info, "Update successfully!", "Update information");
    }

    accept();
}

