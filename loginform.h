#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

enum class MessageType {
    Info,
    Warning
};


// Forward declare Ui::maindialog
namespace Ui {
class mainDialog;
}

class QAction;

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void onTogglePasswordVisibility(); // Slot để bật/tắt hiển thị mật khẩu

    void on_signInButton_clicked();

private:
    void applyStyles(); // Hàm tải file QSS

    inline void showMessage(QWidget* parent, MessageType type, const QString& text, const QString& title = "Notification");

    Ui::mainDialog *ui; // Con trỏ trỏ tới các widget trong file .ui
    QAction *togglePasswordAction; // Vẫn cần cái này cho icon con mắt
};

#endif // LOGINFORM_H
