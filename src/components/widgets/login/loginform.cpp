#include "loginform.h"
#include "ui_loginform.h"
#include "src/components/dialogs/msg/inform.h"
#include "src/utils/usermanager.h"

LoginForm::LoginForm(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , repo(repo)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_signUpLabel_linkActivated(const QString &_)
{
    emit requestSignUp();
}


void LoginForm::on_signInButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập tên đăng nhập!", "Lỗi đăng nhập");
        ui->usernameEdit->setFocus();
        return;
    }

    if (password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập mật khẩu!", "Lỗi đăng nhập");
        ui->passwordEdit->setFocus();
        return;
    }

    bool isValid = UserManager::login(username, password);

    if (isValid) {
        emit loginSuccess(username);

        ui->passwordEdit->clear();

        Inform::showMessage(this, MessageType::Info, "Đăng nhập thàng công!", "Thành công");
    } else {
        Inform::showMessage(this, MessageType::Warning, "Tên đăng nhập hoặc mật khẩu không đúng!", "Đăng nhập thất bại");

        ui->usernameEdit->clear();
        ui->passwordEdit->setFocus();
    }
}
