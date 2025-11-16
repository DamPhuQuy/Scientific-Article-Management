#ifndef AUTHORMANAGEMENTWIDGET_H
#define AUTHORMANAGEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class AuthorManagementWidget;
}

/**
 * @brief Widget Giao diện Quản lý Tác giả
 *
 * Hiển thị các tùy chọn để quản lý tác giả (thêm, xem, sửa, xóa...).
 * Phát ra tín hiệu cho MainWindow để xử lý các hành động này.
 */
class AuthorManagementWidget : public QWidget
{
    Q_OBJECT // Bắt buộc cho signals/slots

public:
    explicit AuthorManagementWidget(QWidget *parent = nullptr);
    ~AuthorManagementWidget();

signals:
    // Tín hiệu cho từng hành động quản lý tác giả
    void createAuthorRequested();
    void viewAllAuthorsRequested();
    void updateAuthorRequested();
    void deleteAuthorRequested();
    void searchAuthorsRequested();
    void showStatisticsRequested();
    void backToMainMenuRequested(); // Tín hiệu để quay lại menu chính

private:
    Ui::AuthorManagementWidget *ui; // Con trỏ tới các thành phần UI
};

#endif // AUTHORMANAGEMENTWIDGET_H