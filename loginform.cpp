#include "loginform.h"
#include "ui_loginform.h"
#include <QIcon>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include "./src/utils/usermanager.h"

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);

    // === BƯỚC 2: GỌI setStyleSheet TRỰC TIẾP ===
    applyStyles();

    // === BƯỚC 3: Thêm logic (giữ nguyên) ===
    togglePasswordAction = ui->passwordEdit->addAction(QIcon(":/images/hide.png"), QLineEdit::TrailingPosition);
    togglePasswordAction->setCheckable(true);

    // === BƯỚC 4: Kết nối Signals và Slots (giữ nguyên) ===
    connect(togglePasswordAction, &QAction::triggered, this, &LoginForm::onTogglePasswordVisibility);
    ui->passwordEdit->setMinimumWidth(250);

    // connect(ui->forgotPasswordLabel, &QLabel::linkActivated, this, [](const QString &link){
    //     qDebug("Forgot password link clicked!");
    // });
    connect(ui->signUpLabel, &QLabel::linkActivated, this, &LoginForm::on_signInButton_clicked);
}

LoginForm::~LoginForm()
{
    delete ui;
}

// Hàm bật/tắt hiển thị mật khẩu (giữ nguyên)
void LoginForm::onTogglePasswordVisibility()
{
    if (togglePasswordAction->isChecked()) {
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
        togglePasswordAction->setIcon(QIcon(":/images/view.png"));
    } else {
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
        togglePasswordAction->setIcon(QIcon(":/images/hide.png"));
    }
}

// Hàm applyStyles mới (thay thế cho loadStyles)
void LoginForm::applyStyles()
{
    // === 1. Nền mờ + bo góc cho toàn bộ dialog ===
    setStyleSheet(
        "#mainDialog {"
        "   background: url(:/images/background.png) center center no-repeat;"
        "   background-size: cover;"
        "   border-radius: 20px;"
        "}"

        "QFrame {"
        "background: white;"
        "border-radius: 20px;"
        "}"

        // === 2. Card trung tâm (centralCard) - hiệu ứng kính mờ (frosted glass) ===
        "#centralCard {"
        "   background: rgba(255, 255, 255, 0.88);"
        "   border-radius: 20px;"
        "   border: 1px solid rgba(0, 0, 0, 0.05);"
        "}"

        // === 3. Label tiêu đề ===
        "#titleLabel {"
        "   font-size: 24px;"
        "   font-weight: bold;"
        "   color: #1a1a1a;"
        "   margin-bottom: 4px;"
        "}"

        "#subtitleLabel {"
        "   font-size: 14px;"
        "   color: #666666;"
        "}"

        // === 4. Input fields ===
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

        // === 5. Nút Sign in ===
        "#signInButton {"
        "   background-color: #000000;"
        "   color: white;"
        "   font-weight: bold;"
        "   font-size: 16px;"
        "   border-radius: 12px;"
        "   min-height: 48px;"
        "}"

        "#signInButton:hover {"
        "   background-color: #333333;"
        "}"

        "#signInButton:pressed {"
        "   background-color: #111111;"
        "}"

        // === 6. Checkbox ===
        "QCheckBox {"
        "    color: #555555;"
        "    spacing: 8px;"
        "    font-size: 14px;"
        "    font-family: 'Segoe UI', sans-serif;"
        "}"
        "QCheckBox::indicator {"
        "    width: 18px;"
        "    height: 18px;"
        "    border-radius: 6px;"
        "    border: 2px solid #cccccc;"
        "    background-color: white;"
        "}"
        "QCheckBox::indicator:hover {"
        "    border: 2px solid #999999;"
        "    background-color: #f5f5f5;"
        "}"
        "QCheckBox::indicator:checked {"
        "    border: 2px solid #007AFF;"
        "    image: url(:/images/checkbox.png);"  /* Dấu check */
        "}"
        "QCheckBox::indicator:checked:hover {"
        "    background-color: #0066cc;"
        "    border: 2px solid #0066cc;"
        "}"
        "QCheckBox::indicator:disabled {"
        "    border: 2px solid #e0e0e0;"
        "    background-color: #f5f5f5;"
        "}"
        "QCheckBox::indicator:checked:disabled {"
        "    background-color: #cccccc;"
        "    border: 2px solid #cccccc;"
        "}"

        // === 7. Link (Forgot & Sign up) ===
        "QLabel {"
        "   color: #007AFF;"
        "}"

        "QLabel > a {"
        "   color: #007AFF;"
        "   text-decoration: none;"
        "}"

        "QLabel > a:hover {"
        "   text-decoration: underline;"
        "}"
        );
    // === 10. Hiệu ứng bóng cho card (shadow) ===
    auto *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor(0, 0, 0, 80));

    ui->centralCardFrame->setGraphicsEffect(shadow);

    // === 11. Logo (nếu dùng ảnh) ===
    QPixmap logo(":/images/logo.png");
    if (!logo.isNull()) {
        ui->logoLabel->setPixmap(logo.scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->logoLabel->setText("Logo");
        ui->logoLabel->setStyleSheet("font-size: 48px;");
    }
}

void LoginForm::on_signInButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    bool success = UserManager::verifyLogin(username.toStdString(), password.toStdString());
    if (success) {
        showMessage(this, MessageType::Info, "Login success!", "Login");
    } else {
        showMessage(this, MessageType::Warning, "Invalid username or password", "Login");
    }
}

inline void LoginForm::showMessage(QWidget* parent, MessageType type, const QString& text, const QString& title) {
        QMessageBox msgBox(parent);
        msgBox.setWindowTitle(title);
        msgBox.setText(text);

        QString style = R"(
        QMessageBox {
            background-color: #ffffff;
            border: 1px solid #cccccc;
            border-radius: 8px;
        }
        QMessageBox QLabel {
            min-width: 250px;
            font-size: 14px;
            color: #2c3e50;
        }
        QMessageBox QPushButton {
            min-width: 80px;
            font-size: 13px;
            padding: 4px 8px;
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 4px;
        }
        QMessageBox QPushButton:hover {
            background-color: #2980b9;
        }
        QMessageBox QPushButton:pressed {
            background-color: #1abc9c;
        }
    )";

        msgBox.setStyleSheet(style);

        // Đảm bảo không bị ảnh hưởng bởi parent stylesheet
        msgBox.setModal(true);
        msgBox.exec();

}
