// signupform.cpp
#include "signupform.h"
#include "ui_signupform.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLineEdit>
#include <QGraphicsDropShadowEffect>
#include "./src/utils/usermanager.h"

using json = nlohmann::json;

SignUpForm::SignUpForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpLayout)
{
    ui->setupUi(this);
    applyStyles();

    // === TOGGLE MẬT KHẨU CHO 2 Ô ===
    setupPasswordToggle(ui->passwordEdit);
    setupPasswordToggle(ui->confirmPasswordEdit);

    // Kiểm tra mật khẩu trùng
    connect(ui->confirmPasswordEdit, &QLineEdit::textChanged,
            this, &SignUpForm::on_confirmPasswordEdit_textChanged);
}

SignUpForm::~SignUpForm()
{
    delete ui;
}

void SignUpForm::setupPasswordToggle(QLineEdit *edit)
{
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/images/hide.png"));

    edit->addAction(action, QLineEdit::TrailingPosition);

    // BUGFIX: ép đặt lại Password sau khi addAction
    edit->setEchoMode(QLineEdit::Password);

    action->setProperty("targetEdit", QVariant::fromValue(static_cast<QObject*>(edit)));

    connect(action, &QAction::triggered, this, [this]() {
        QAction *act = qobject_cast<QAction*>(sender());
        if (!act) return;

        QObject *obj = act->property("targetEdit").value<QObject*>();
        QLineEdit *lineEdit = qobject_cast<QLineEdit*>(obj);
        if (!lineEdit) return;

        if (lineEdit->echoMode() == QLineEdit::Password) {
            lineEdit->setEchoMode(QLineEdit::Normal);
            act->setIcon(QIcon(":/images/view.png"));
        } else {
            lineEdit->setEchoMode(QLineEdit::Password);
            act->setIcon(QIcon(":/images/hide.png"));
        }
    });

    edit->setMinimumWidth(250);
}


// === KIỂM TRA MẬT KHẨU TRÙNG ===
void SignUpForm::on_confirmPasswordEdit_textChanged(const QString &text)
{
    QString pass1 = ui->passwordEdit->text();
    if (!text.isEmpty() && !pass1.isEmpty() && text != pass1) {
        ui->confirmPasswordEdit->setStyleSheet(
            "QLineEdit { border: 2px solid red; border-radius: 12px; }"
            );
    } else {
        ui->confirmPasswordEdit->setStyleSheet("");
    }
}

// === NÚT SIGN UP ===
void SignUpForm::on_signUpButton_clicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString pass = ui->passwordEdit->text();
    QString confirm = ui->confirmPasswordEdit->text();

    if (username.isEmpty() || pass.isEmpty() || confirm.isEmpty()) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng điền đầy đủ!");
        return;
    }
    if (pass != confirm) {
        QMessageBox::warning(this, "Lỗi", "Mật khẩu không khớp!");
        return;
    }
    if (pass.length() < 6) {
        QMessageBox::warning(this, "Lỗi", "Mật khẩu ít nhất 6 ký tự!");
        return;
    }

    // === KIỂM TRA TRÙNG ===
    if (UserManager::userExists(username)) {
        QMessageBox::warning(this, "Lỗi", "Tên đăng nhập đã tồn tại!");
        return;
    }

    // === THÊM USER MỚI ===
    if (!UserManager::addUser(username, pass)) {
        QMessageBox::warning(this, "Lỗi", "Lưu thất bại!");
        return;
    }

    // === THÔNG BÁO THÀNH CÔNG + TỰ VỀ LOGIN ===
    QMessageBox *msg = new QMessageBox(this);
    msg->setWindowTitle("Thành công");
    msg->setText("Đăng ký thành công!\nChào " + username + "!");
    msg->setIcon(QMessageBox::Information);
    msg->setStyleSheet(R"(
        QMessageBox { background: white; border-radius: 8px; }
        QMessageBox QLabel { font-size: 14px; color: #2c3e50; }
        QMessageBox QPushButton {
            background: #3498db; color: white; border-radius: 4px;
            min-width: 80px; padding: 6px;
        }
        QMessageBox QPushButton:hover { background: #2980b9; }
    )");

    connect(msg, &QMessageBox::accepted, this, [this, username, pass]() {
        json data = {
            {"username", username.toStdString()},
            {"password", pass.toStdString()}
        };
        UserManager::saveUsers(data);
        emit backToLogin();
    });

    msg->exec();
}

// === STYLE ĐỒNG BỘ ===
void SignUpForm::applyStyles()
{
    // DÙNG `this` ĐỂ ÁP BACKGROUND
    this->setStyleSheet(
        "SignUpForm {"
        " background: url(:/images/background.png) center center no-repeat;"
        " background-size: cover;"
        " border-radius: 20px;"
        "}"
        "#centralCardFrame {"
        " background: rgba(255,255,255,0.90); border-radius: 20px;"
        "}"
        "#centralCard {"
        " background: rgba(255,255,255,0.88); border-radius: 20px;"
        " border: 1px solid rgba(0,0,0,0.05);"
        "}"
        "#titleLabel { font: bold 26px; color: #1a1a1a; }"
        "#subtitleLabel { font: 14px; color: #666; }"
        "QLineEdit {"
        "   border: 1.5px solid #e0e0e0;"
        "   border-radius: 12px;"
        "   padding: 12px 16px;"
        "   font-size: 15px;"
        "   background-color: rgba(255, 255, 255, 0.9);"
        "   color: #000000;"
        "   selection-color: white; "
        "   selection-background-color: #007AFF;"
        "}"

        "QLineEdit:focus {"
        "   border: 2px solid #007AFF;"
        "   background-color: white;"
        "   color: #000000; "
        "}"
        "#signUpButton {"
        " background: black; color: white; font: bold 16px;"
        " border-radius: 12px; min-height: 48px;"
        "}"
        "#signUpButton:hover { background: #333; }"
        "#signUpButton:pressed { background: #111; }"
        "QLabel { color: #007AFF; font: 14px; }"
        );

    // Shadow
    auto *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setColor(QColor(0,0,0,80));
    ui->centralCardFrame->setGraphicsEffect(shadow);

    // Logo
    QPixmap logo(":/images/logo.png");
    if (!logo.isNull()) {
        ui->logoLabel->setPixmap(logo.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    } else {
        ui->logoLabel->setText("Logo");
        ui->logoLabel->setStyleSheet("font: 48px; color: #007AFF;");
    }
}
