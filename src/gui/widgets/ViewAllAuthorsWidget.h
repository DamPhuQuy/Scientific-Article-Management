#ifndef VIEWALLAUTHORSWIDGET_H
#define VIEWALLAUTHORSWIDGET_H

#include <QWidget>
#include <QList>
#include "models/Author.h" // Cần model Author

namespace Ui {
class ViewAllAuthorsWidget;
}

/**
 * @brief Widget chính để xem, tìm kiếm và quản lý tác giả.
 *
 * Widget này thay thế AuthorManagementWidget (Tiến trình 4) và
 * SearchAuthorDialog (Tiến trình 7), hợp nhất logic của
 * author_sub_menu vào một trang duy nhất.
 */
class ViewAllAuthorsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewAllAuthorsWidget(QWidget *parent = nullptr);
    ~ViewAllAuthorsWidget();

    /**
     * @brief Nạp (hoặc nạp lại) dữ liệu tác giả vào bảng.
     * @param allAuthors Danh sách TẤT CẢ tác giả từ service.
     */
    void loadData(const QList<Author>& allAuthors);

signals:
    // Các tín hiệu này thay thế các lựa chọn trong author_sub_menu
    void createRequested();      // case 0
    void updateRequested(Author author); // case 2
    void deleteRequested(Author author); // case 3
    void statsRequested();       // case 5
    void backRequested();        // case 6

private slots:
    // Slots cho các nút bấm
    void onCreateClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onStatsClicked();

    // Slots cho tìm kiếm (thay thế case 4)
    void onSearchTextChanged(const QString &text);
    void onCriteriaChanged(int index);

    // Slot để bật/tắt nút "Edit" và "Delete"
    void onSelectionChanged();

private:
    void setupTable();
    void populateCriteriaComboBox();

    /**
     * @brief Cập nhật bảng chỉ với các tác giả trong danh sách này.
     * @param authors Danh sách tác giả (đã lọc hoặc đầy đủ).
     */
    void populateTable(const QList<Author>& authors);

    /**
     * @brief Lấy đối tượng Author từ hàng hiện tại đang được chọn.
     * @return Đối tượng Author hoặc một đối tượng rỗng nếu không có gì được chọn.
     */
    Author getSelectedAuthor() const;

    Ui::ViewAllAuthorsWidget *ui;

    QList<Author> m_allAuthors; // Danh sách gốc, đầy đủ
};

#endif // VIEWALLAUTHORSWIDGET_H