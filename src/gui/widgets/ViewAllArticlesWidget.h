#ifndef VIEWALLARTICLESWIDGET_H
#define VIEWALLARTICLESWIDGET_H

#include <QWidget>
#include <QList>
#include "models/articles/Article.h" // Cần base class Article

namespace Ui {
class ViewAllArticlesWidget;
}

/**
 * @brief Widget chính để xem, tìm kiếm và quản lý bài báo.
 *
 * Widget này thay thế ArticleManagementWidget (Tiến trình 3) và
 * SearchArticleDialog (Tiến trình 8), hợp nhất logic của
 * article_sub_menu vào một trang duy nhất.
 */
class ViewAllArticlesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewAllArticlesWidget(QWidget *parent = nullptr);
    ~ViewAllArticlesWidget();

    /**
     * @brief Nạp (hoặc nạp lại) dữ liệu bài báo vào bảng.
     * @param allArticles Danh sách TẤT CẢ bài báo từ service.
     */
    void loadData(const QList<Article*>& allArticles);

signals:
    // Các tín hiệu này thay thế các lựa chọn trong article_sub_menu
    void createRequested();      // case 0
    void updateRequested(Article* article); // case 2
    void deleteRequested(Article* article); // case 3
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
     * @brief Cập nhật bảng chỉ với các bài báo trong danh sách này.
     * @param articles Danh sách bài báo (đã lọc hoặc đầy đủ).
     */
    void populateTable(const QList<Article*>& articles);

    /**
     * @brief Lấy con trỏ Article* từ hàng hiện tại đang được chọn.
     * @return Con trỏ Article* hoặc nullptr nếu không có gì được chọn.
     */
    Article* getSelectedArticle() const;

    Ui::ViewAllArticlesWidget *ui;

    QList<Article*> m_allArticles; // Danh sách gốc, đầy đủ
};

#endif // VIEWALLARTICLESWIDGET_H