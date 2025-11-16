#ifndef SEARCHARTICLEDIALOG_H
#define SEARCHARTICLEDIALOG_H

#include <QDialog>
#include <QList>
#include "models/articles/Article.h" // Include Article.h (hoặc base class)

namespace Ui {
class SearchArticleDialog;
}

class SearchArticleDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param allArticles Danh sách TẤT CẢ bài báo để thực hiện tìm kiếm.
     * @param parent Widget cha.
     */
    explicit SearchArticleDialog(const QList<Article*>& allArticles, QWidget *parent = nullptr);
    ~SearchArticleDialog();

    /**
     * @brief Lấy con trỏ tới bài báo đã được người dùng chọn.
     * @return Con trỏ tới Article đã chọn, hoặc nullptr nếu không chọn.
     */
    Article* getSelectedArticle() const;

private slots:
    // Các slot cho "live search"
    void onSearchTextChanged(const QString &text);
    void onCriteriaChanged(int index);
    
    // Slots để xử lý việc chọn
    void onRowSelected();
    void onRowDoubleClicked(int row, int column);

private:
    void setupTable();
    void populateCriteriaComboBox();
    void populateTable(const QList<Article*>& articles);

    Ui::SearchArticleDialog *ui;

    QList<Article*> m_allArticles; // Danh sách gốc
    Article* m_selectedArticle;    // Bài báo được chọn
};

#endif // SEARCHARTICLEDIALOG_H