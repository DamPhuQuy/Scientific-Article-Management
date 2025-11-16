#ifndef ADDAUTHORDIALOG_H
#define ADDAUTHORDIALOG_H

#include <QDialog>
#include "models/Author.h" // Phải include model Author của bạn

namespace Ui {
class AddAuthorDialog;
}

class AddAuthorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAuthorDialog(QWidget *parent = nullptr);
    ~AddAuthorDialog();

    /**
     * @brief Lấy dữ liệu Author đã được người dùng nhập vào dialog.
     * @return Một đối tượng Author chứa thông tin từ các trường UI.
     * @note Hàm này KHÔNG tạo ID. ID sẽ được tạo bởi Service/Repo.
     */
    Author getAuthorData() const;

private slots:
    /**
     * @brief Slot để kiểm tra tính hợp lệ của dữ liệu nhập.
     * Sẽ vô hiệu hóa nút "OK" nếu tên (Full Name) bị trống.
     */
    void validateInput();

private:
    Ui::AddAuthorDialog *ui;
};

#endif // ADDAUTHORDIALOG_H