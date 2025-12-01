#include "signupform.h"
#include "ui_signupform.h"
#include "src/utils/usermanager.h"
#include "src/utils/constants.h"
#include "src/components/dialogs/msg/inform.h"
#include <QRegularExpression>
#include <QTimer>
#include <QInputDialog>

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
    // Reset tất cả style trước khi validate
    ui->usernameEdit->setStyleSheet("");
    ui->passwordEdit->setStyleSheet("");
    ui->confirmPassEdit->setStyleSheet("");
    ui->fullnameEdit->setStyleSheet("");
    ui->emailEdit->setStyleSheet("");
    ui->phoneEdit->setStyleSheet("");

    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirmPass = ui->confirmPassEdit->text();
    QString fullname = ui->fullnameEdit->text().trimmed();
    QString email = ui->emailEdit->text().trimmed();
    QString phone = ui->phoneEdit->text().trimmed();

    // empty fields validation
    if (username.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập tên đăng nhập!", "Lỗi đăng kí");
        ui->usernameEdit->setFocus();
        return;
    }

    if (password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập mật khẩu!", "Lỗi đăng kí");
        ui->passwordEdit->setFocus();
        return;
    }

    if (confirmPass.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng xác nhận mật khẩu!", "Lỗi đăng kí");
        ui->confirmPassEdit->setFocus();
        return;
    }

    if (fullname.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập họ tên!", "Lỗi đăng kí");
        ui->fullnameEdit->setFocus();
        return;
    }

    if (email.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập email!", "Lỗi đăng kí");
        ui->emailEdit->setFocus();
        return;
    }

    if (phone.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Vui lòng nhập số điện thoại!", "Lỗi đăng kí");
        ui->phoneEdit->setFocus();
        return;
    }

    // format validation
    if (username.contains(' ') || username.length() < 3) {
        Inform::showMessage(this, MessageType::Warning, "Tên đăng nhập phải >= 3 ký tự và không chứa khoảng trắng!", "Lỗi đăng kí");
        ui->usernameEdit->setFocus();
        ui->usernameEdit->selectAll();
        return;
    }

    if (password.length() < 6) {
        Inform::showMessage(this, MessageType::Warning, "Mật khẩu phải >= 6 ký tự!", "Lỗi đăng kí");
        ui->passwordEdit->setFocus();
        ui->passwordEdit->selectAll();
        return;
    }

    QRegularExpression pwRegex(R"((?=.*[A-Za-z])(?=.*\d).{6,})");
    if (!pwRegex.match(password).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Mật khẩu phải chứa cả chữ và số!", "Lỗi đăng kí");
        ui->passwordEdit->setFocus();
        ui->passwordEdit->selectAll();
        return;
    }

    if (password != confirmPass) {
        Inform::showMessage(this, MessageType::Warning, "Mật khẩu không trùng khớp!", "Lỗi đăng kí");
        ui->confirmPassEdit->setFocus();
        ui->confirmPassEdit->selectAll();
        return;
    }

    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Email không hợp lệ!", "Lỗi đăng kí");
        ui->emailEdit->setFocus();
        ui->emailEdit->selectAll();
        return;
    }

    QRegularExpression phoneRegex(R"(^\+?\d{9,15}$)");
    if (!phoneRegex.match(phone).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Số điện thoại không hợp lệ (9-15 chữ số)!", "Lỗi đăng kí");
        ui->phoneEdit->setFocus();
        ui->phoneEdit->selectAll();
        return;
    }

    // duplicates validation
    QStringList duplicateErrors;
    QList<QLineEdit*> errorFields;

    if (UserManager::userExists(username)) {
        duplicateErrors << "• Tên đăng nhập đã tồn tại";
        errorFields << ui->usernameEdit;
    }

    if (UserManager::emailExists(email)) {
        duplicateErrors << "• Email đã được sử dụng";
        errorFields << ui->emailEdit;
    }

    if (UserManager::phoneExists(phone)) {
        duplicateErrors << "• Số điện thoại đã được sử dụng";
        errorFields << ui->phoneEdit;
    }

    if (!duplicateErrors.isEmpty()) {
        QString errorMessage = "Thông tin bị trùng lặp:\n\n" + duplicateErrors.join("\n");

        // highlight
        for (QLineEdit* field : errorFields) {
            field->setStyleSheet("QLineEdit { border: 2px solid #ff6b6b; background-color: #ffe0e0; }");
            field->selectAll();
        }

        Inform::showMessage(this, MessageType::Warning, errorMessage, "Lỗi đăng kí");

        return;
    }

    // get role
    QString role = ui->userRadioButton->isChecked() ? "User" : "Admin";

    // role is Admin, ask for admin code
    if (role == "Admin") {
        bool ok;
        QString adminCode = QInputDialog::getText(this,
                                                   "Xác thực Admin",
                                                   "Nhập mã admin để tạo tài khoản Admin:",
                                                   QLineEdit::Password,
                                                   QString(),
                                                   &ok);

        if (!ok) {
            // cancel
            return;
        }

        if (adminCode.trimmed() != QString::fromStdString(ADMIN_CODE)) {
            Inform::showMessage(this, MessageType::Warning, "Mã admin không đúng!", "Lỗi xác thực");
            return;
        }
    }

    UserManager::registerUser(username, password, fullname, email, phone, role);

    Inform::showMessage(this, MessageType::Info, "Đăng kí thành công! Vui lòng đăng nhập.", "Thành công");

    emit signupSuccess();
}

