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

    // Setup Login Link
    ui->loginLabel->setText("<a href=\"login\" style=\"text-decoration:none; color:#20B2AA;\">Đăng nhập</a>");
    ui->loginLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    // Setup toogle checkbox for password fields
    ui->showPasswordCheckBox->setCheckable(true);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPassEdit->setEchoMode(QLineEdit::Password);
    connect(ui->showPasswordCheckBox, &QCheckBox::toggled, this, [=](bool checked){
        ui->passwordEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
        ui->confirmPassEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });

    QPixmap pix(":/icons/public/resources/view.png");
    qDebug() << "Is pixmap null?" << pix.isNull();
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
    QString fullname = ui->fullnameEdit->text();
    QString email = ui->emailEdit->text();
    QString phone = ui->phoneEdit->text();

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

    UserManager::registerUser(username, password, fullname, email, phone);
    emit signupSuccess();
}

