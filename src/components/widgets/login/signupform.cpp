#include "signupform.h"
#include "ui_signupform.h"
#include "src/utils/usermanager.h"
#include "src/components/dialogs/msg/inform.h"

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

void SignUpForm::on_loginLabel_linkActivated()
{
    emit requestBack();
}


void SignUpForm::on_signUpButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirmPass = ui->confirmPassEdit->text();

    if (username.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập tên đăng nhập!", "Lỗi đăng kí");
        return;
    }

    if (password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập mật khẩu!", "Lỗi đăng kí");
        return;
    }

    if (UserManager::userExists(username)) {
        Inform::showMessage(this, MessageType::Warning, "Tên đăng nhập đã tồn tại!", "Lỗi đăng kí");
        return;
    }

    if (password != confirmPass) {
        Inform::showMessage(this, MessageType::Warning, "Mật khẩu không trùng!", "Lỗi đăng kí");
        return;
    }

    UserManager::registerUser(username, password);
    emit signupSuccess();
}

