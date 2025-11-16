#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

// Forward declaration của lớp UI được Qt sinh ra
namespace Ui {
class MainMenuWidget;
}

/**
 * @brief Widget Giao diện Menu Chính
 *
 * Widget này hiển thị các tùy chọn điều hướng cấp cao nhất.
 * Nó không chứa logic nghiệp vụ, mà chỉ phát ra tín hiệu (signals)
 * khi các nút được nhấn. MainWindow sẽ bắt các tín hiệu này
 * để chuyển đổi giao diện hoặc thực hiện hành động.
 */
class MainMenuWidget : public QWidget
{
    Q_OBJECT // Bắt buộc cho các lớp có signals/slots

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

signals:
    /**
     * @brief Tín hiệu được phát ra khi người dùng nhấn nút "Manage Articles".
     */
    void manageArticlesClicked();

    /**
     * @brief Tín hiệu được phát ra khi người dùng nhấn nút "Manage Authors".
     */
    void manageAuthorsClicked();

    /**
     * @brief Tín hiệu được phát ra khi người dùng nhấn nút "Exit".
     */
    void exitClicked();

private:
    Ui::MainMenuWidget *ui; // Con trỏ tới các thành phần UI (từ file .ui)
};

#endif // MAINMENUWIDGET_H