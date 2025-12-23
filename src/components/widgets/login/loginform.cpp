#include "loginform.h"
#include "ui_loginform.h"
#include "src/components/dialogs/msg/inform.h"
#include "src/utils/usermanager.h"
#include <QDebug>

LoginForm::LoginForm(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , repo(repo)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    // Setup Sign Up Link
    ui->signUpLabel->setText("<a href=\"signup\" style=\"text-decoration:none; color:#20B2AA;\">Sign Up</a>");
    ui->signUpLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    // Setup toggle checkbox for password visibility
    ui->showPasswordCheckBox->setCheckable(true);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    connect(ui->showPasswordCheckBox, &QCheckBox::toggled, this, [=](bool checked){
        ui->passwordEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });
    ui->showPasswordCheckBox->setStyleSheet(
    R"(
    QCheckBox::indicator {
        width: 20px;
        height: 20px;
    }
    QCheckBox::indicator:unchecked {
        border: 1px solid #777;
        image: url(:/icons/public/resources/hide.png);
    }
    QCheckBox::indicator:checked {
        border: 1px solid #777;
        image: url(:/icons/public/resources/view.png);
    }
    )"
    );
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
        Inform::showMessage(this, MessageType::Warning, "Please enter username, email or phone number!", "Login Error");
        ui->usernameEdit->setFocus();
        return;
    }

    if (password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please enter password!", "Login Error");
        ui->passwordEdit->setFocus();
        return;
    }

    if (username.isEmpty() && password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please fill in all information", "Login Error");
        ui->usernameEdit->setFocus();
        ui->passwordEdit->setFocus();
        return;
    }

    qDebug() << "Username: " << username << " - " << "Password: " << password;

    bool isValid = repo.getUsers().login(username, password);

    if (isValid) {
        QString actualUsername = repo.getUsers().getUsernameFromIdentifier(username);
        emit loginSuccess(actualUsername);

        ui->passwordEdit->clear();

        Inform::showMessage(this, MessageType::Info, "Login successful!", "Success");
    } else {
        Inform::showMessage(this, MessageType::Warning, "Incorrect username or password!", "Login Failed");

        ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        ui->usernameEdit->setFocus();
    }
}

