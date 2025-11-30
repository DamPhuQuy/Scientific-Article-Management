#include "signupform.h"
#include "ui_signupform.h"
#include "src/utils/usermanager.h"
#include "src/components/dialogs/msg/inform.h"
#include <QRegularExpression>

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

    // Extra input validation
    if (fullname.trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập họ tên!", "Lỗi đăng kí");
        return;
    }

    if (email.trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập email!", "Lỗi đăng kí");
        return;
    } else {
        QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        if (!emailRegex.match(email).hasMatch()) {
            Inform::showMessage(this, MessageType::Warning, "Email không hợp lệ!", "Lỗi đăng kí");
            return;
        }
    }

    if (phone.trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập số điện thoại!", "Lỗi đăng kí");
        return;
    } else {
        QRegularExpression phoneRegex(R"(^\+?\d{9,15}$)");
        if (!phoneRegex.match(phone).hasMatch()) {
            Inform::showMessage(this, MessageType::Warning, "Số điện thoại không hợp lệ!", "Lỗi đăng kí");
            return;
        }
    }

    if (username.contains(' ') || username.length() < 3) {
        Inform::showMessage(this, MessageType::Warning, "Tên đăng nhập phải >= 3 ký tự và không chứa khoảng trắng!", "Lỗi đăng kí");
        return;
    }

    if (password.length() < 6) {
        Inform::showMessage(this, MessageType::Warning, "Mật khẩu phải >= 6 ký tự!", "Lỗi đăng kí");
        return;
    } else {
        QRegularExpression pwRegex(R"((?=.*[A-Za-z])(?=.*\d).{6,})");
        if (!pwRegex.match(password).hasMatch()) {
            Inform::showMessage(this, MessageType::Warning, "Mật khẩu phải chứa cả chữ và số!", "Lỗi đăng kí");
            return;
        }
    }

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

    Inform::showMessage(this, MessageType::Info, "Đăng kí thành công! Vui lòng đăng nhập.", "Thành công");

    emit signupSuccess();
}

