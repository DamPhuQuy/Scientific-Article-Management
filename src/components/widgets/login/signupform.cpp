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
    ui->loginLabel->setText("<a href=\"login\" style=\"text-decoration:none; color:#20B2AA;\">Login</a>");
    ui->loginLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    // Setup toogle checkbox for password fields
    ui->showPasswordCheckBox->setCheckable(true);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPassEdit->setEchoMode(QLineEdit::Password);
    connect(ui->showPasswordCheckBox, &QCheckBox::toggled, this, [=](bool checked){
        ui->passwordEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
        ui->confirmPassEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });

    // QPixmap pix(":/icons/public/resources/view.png");
    // qDebug() << "Is pixmap null?" << pix.isNull();
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
    // reset styles
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
        Inform::showMessage(this, MessageType::Warning, "Please enter username!", "Registration Error");
        ui->usernameEdit->setFocus();
        return;
    }

    if (password.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please enter password!", "Registration Error");
        ui->passwordEdit->setFocus();
        return;
    }

    if (confirmPass.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please confirm password!", "Registration Error");
        ui->confirmPassEdit->setFocus();
        return;
    }

    if (fullname.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please enter full name!", "Registration Error");
        ui->fullnameEdit->setFocus();
        return;
    }

    if (email.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please enter email!", "Registration Error");
        ui->emailEdit->setFocus();
        return;
    }

    if (phone.isEmpty()) {
        Inform::showMessage(this, MessageType::Warning, "Please enter phone number!", "Registration Error");
        ui->phoneEdit->setFocus();
        return;
    }

    // format validation
    if (username.contains(' ') || username.length() < 3) {
        Inform::showMessage(this, MessageType::Warning, "Username must be >= 3 characters and contain no spaces!", "Registration Error");
        ui->usernameEdit->setFocus();
        ui->usernameEdit->selectAll();
        return;
    }

    if (password.length() < 8) {
        Inform::showMessage(this, MessageType::Warning, "Password must be >= 8 characters!", "Registration Error");
        ui->passwordEdit->setFocus();
        ui->passwordEdit->selectAll();
        return;
    }

    QRegularExpression pwRegex(R"((?=.*[A-Za-z])(?=.*\d).{8,})");
    if (!pwRegex.match(password).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Password must contain both letters and numbers!", "Registration Error");
        ui->passwordEdit->setFocus();
        ui->passwordEdit->selectAll();
        return;
    }

    if (password != confirmPass) {
        Inform::showMessage(this, MessageType::Warning, "Passwords do not match!", "Registration Error");
        ui->confirmPassEdit->setFocus();
        ui->confirmPassEdit->selectAll();
        return;
    }

    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Invalid email!", "Registration Error");
        ui->emailEdit->setFocus();
        ui->emailEdit->selectAll();
        return;
    }

    QRegularExpression phoneRegex(R"(^\+?\d{9,15}$)");
    if (!phoneRegex.match(phone).hasMatch()) {
        Inform::showMessage(this, MessageType::Warning, "Invalid phone number (9-15 digits)!", "Registration Error");
        ui->phoneEdit->setFocus();
        ui->phoneEdit->selectAll();
        return;
    }

    // duplicates validation
    QStringList duplicateErrors;
    QList<QLineEdit*> errorFields;

    if (UserManager::userExists(username)) {
        duplicateErrors << "• Username already exists";
        errorFields << ui->usernameEdit;
    }

    if (UserManager::emailExists(email)) {
        duplicateErrors << "• Email already in use";
        errorFields << ui->emailEdit;
    }

    if (UserManager::phoneExists(phone)) {
        duplicateErrors << "• Phone number already in use";
        errorFields << ui->phoneEdit;
    }

    if (!duplicateErrors.isEmpty()) {
        QString errorMessage = "The information is duplicated:\n\n" + duplicateErrors.join("\n");

        // highlight
        for (QLineEdit* field : errorFields) {
            field->setStyleSheet("QLineEdit { border: 2px solid #ff6b6b; background-color: #ffe0e0; }");
            field->selectAll();
        }

        Inform::showMessage(this, MessageType::Warning, errorMessage, "Registration Error");

        return;
    }

    // get role
    QString role = ui->userRadioButton->isChecked() ? "User" : "Admin";

    // admin code when role is admin
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
            Inform::showMessage(this, MessageType::Warning, "Incorrect admin code!", "Authentication Error");
            return;
        }
    }

    UserManager::registerUser(username, password, fullname, email, phone, role);

    Inform::showMessage(this, MessageType::Info, "Registration successful! Please login.", "Success");

    emit signupSuccess();
}

