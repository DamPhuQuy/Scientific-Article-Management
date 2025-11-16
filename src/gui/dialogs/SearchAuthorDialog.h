#ifndef SEARCHAUTHORDIALOG_H
#define SEARCHAUTHORDIALOG_H

#include <QDialog>
#include <QList>
#include "models/Author.h" // Include model Author của bạn

namespace Ui {
class SearchAuthorDialog;
}

class SearchAuthorDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param allAuthors Danh sách TẤT CẢ tác giả để thực hiện tìm kiếm.
     * @param parent Widget cha.
     */
    explicit SearchAuthorDialog(const QList<Author>& allAuthors, QWidget *parent = nullptr);
    ~SearchAuthorDialog();

    /**
     * @brief Lấy đối tượng Author đầy đủ mà người dùng đã chọn.
     * @return Đối tượng Author đã chọn.
     */
    Author getSelectedAuthor() const;

private slots:
    /**
     * @brief Được gọi khi nội dung trong QLineEdit thay đổi (live search).
     */
    void onSearchTextChanged(const QString &text);

    /**
     * @brief Được gọi khi QComboBox thay đổi (để thay đổi tiêu chí tìm kiếm).
     */
    void onCriteriaChanged(int index);

    /**
     * @brief Kích hoạt nút "OK" khi một hàng được chọn.
     */
    void onRowSelected();

    /**
     * @brief Chấp nhận (accept) dialog khi double-click một hàng.
     */
    void onRowDoubleClicked(int row, int column);

private:
    /**
     * @brief Thiết lập các cột cho QTableWidget.
     */
    void setupTable();

    /**
     * @brief Điền các mục vào QComboBox tiêu chí.
     */
    void populateCriteriaComboBox();

    /**
     * @brief Cập nhật QTableWidget với danh sách tác giả đã lọc.
     * @param authors Danh sách tác giả để hiển thị.
     */
    void populateTable(const QList<Author>& authors);

    Ui::SearchAuthorDialog *ui;

    QList<Author> m_allAuthors; // Danh sách gốc
    Author m_selectedAuthor;    // Tác giả được chọn
};

#endif // SEARCHAUTHORDIALOG_H