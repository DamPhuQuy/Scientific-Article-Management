#ifndef ARTICLESTATISTICSWIDGET_H
#define ARTICLESTATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class ArticleStatisticsWidget;
}

/**
 * @brief Widget Giao diện Thống kê Bài báo
 *
 * Hiển thị các tùy chọn để xem thống kê (theo năm, theo loại).
 * Phát ra tín hiệu cho MainWindow để xử lý các hành động này.
 */
class ArticleStatisticsWidget : public QWidget
{
    Q_OBJECT // Bắt buộc cho signals/slots

public:
    explicit ArticleStatisticsWidget(QWidget *parent = nullptr);
    ~ArticleStatisticsWidget();

signals:
    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Statistics by Year".
     */
    void statsByYearRequested();

    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Statistics by Type".
     */
    void statsByTypeRequested();

    /**
     * @brief Tín hiệu phát ra khi nhấn nút "Back".
     */
    void backClicked();

private:
    Ui::ArticleStatisticsWidget *ui; // Con trỏ tới các thành phần UI
};

#endif // ARTICLESTATISTICSWIDGET_H