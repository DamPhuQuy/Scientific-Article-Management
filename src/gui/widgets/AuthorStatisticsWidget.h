#ifndef AUTHORSTATISTICSWIDGET_H
#define AUTHORSTATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class AuthorStatisticsWidget;
}

/**
 * @brief Widget Giao diện Thống kê Tác giả
 *
 * Hiển thị các tùy chọn để xem thống kê (theo quốc gia, lĩnh vực, v.v.).
 * Phát ra tín hiệu cho MainWindow để xử lý các hành động này.
 */
class AuthorStatisticsWidget : public QWidget
{
    Q_OBJECT // Bắt buộc cho signals/slots

public:
    explicit AuthorStatisticsWidget(QWidget *parent = nullptr);
    ~AuthorStatisticsWidget();

signals:
    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Statistics by Country".
     */
    void statsByCountryRequested();

    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Statistics by Field of Study".
     */
    void statsByFieldRequested();

    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Top Authors".
     */
    void topAuthorsRequested();

    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Back".
     */
    void backClicked();

private:
    Ui::AuthorStatisticsWidget *ui; // Con trỏ tới các thành phần UI
};

#endif // AUTHORSTATISTICSWIDGET_H