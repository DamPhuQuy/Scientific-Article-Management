#ifndef EDITAUTHORDIALOG_H
#define EDITAUTHORDIALOG_H

#include <QDialog>
#include "models/Author.h" // Include model Author

namespace Ui {
class EditAuthorDialog;
}

class EditAuthorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditAuthorDialog(QWidget *parent = nullptr);
    ~EditAuthorDialog();

    /**
     * @brief Điền dữ liệu của tác giả hiện tại vào các trường UI.
     * @param author Đối tượng Author cần chỉnh sửa.
     */
    void setAuthorData(const Author& author);

    /**
     * @brief Lấy dữ liệu đã được cập nhật từ các trường UI.
     * @return Một đối tượng Author chứa thông tin đã cập nhật.
     */
    Author getAuthorData() const;

private slots:
    /**
     * @brief Slot để kiểm tra tính hợp lệ của dữ liệu (ví dụ: Tên không được trống).
     */
    void validateInput();

private:
    Ui::EditAuthorDialog *ui;
    
    // Phải lưu ID gốc để trả về cùng với dữ liệu đã cập nhật
    std::string m_authorId; 
};

#endif // EDITAUTHORDIALOG_H