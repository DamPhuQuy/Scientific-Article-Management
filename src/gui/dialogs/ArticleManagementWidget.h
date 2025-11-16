#ifndef ARTICLEMANAGEMENTWIDGET_H
#define ARTICLEMANAGEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class ArticleManagementWidget;
}

/**
 * @brief Widget Giao diện Quản lý Bài báo
 *
 * Widget này hiển thị các tùy chọn để quản lý các bài báo khoa học.
 * Nó phát ra các tín hiệu khi người dùng chọn một hành động.
 * Logic nghiệp vụ sẽ được xử lý bởi MainWindow hoặc các service tương ứng.
 */
class ArticleManagementWidget : public QWidget
{
    Q_OBJECT // Bắt buộc cho các lớp có signals/slots

public:
    explicit ArticleManagementWidget(QWidget *parent = nullptr);
    ~ArticleManagementWidget();

signals:
    // Các tín hiệu cho từng hành động quản lý bài báo
    void createArticleRequested();
    void viewAllArticlesRequested();
    void updateArticleRequested();
    void deleteArticleRequested();
    void searchArticlesRequested();
    void showStatisticsRequested();
    void backToMainMenuRequested(); // Tín hiệu để quay lại menu chính

private:
    Ui::ArticleManagementWidget *ui; // Con trỏ tới các thành phần UI
};

#endif // ARTICLEMANAGEMENTWIDGET_H