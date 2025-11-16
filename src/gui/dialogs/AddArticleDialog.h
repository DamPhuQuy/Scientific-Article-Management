#ifndef ADDARTICLEDIALOG_H
#define ADDARTICLEDIALOG_H

#include <QDialog>
#include <QList>
#include "models/Author.h"
#include "models/articles/Article.h" // Cần để lấy enum Type và ArticleStatus

// Forward declare các lớp UI và Model
namespace Ui {
class AddArticleDialog;
}

class AddArticleDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     * @param allAuthors Danh sách tất cả tác giả hiện có để hiển thị trong Tab 2
     * @param parent Widget cha
     */
    explicit AddArticleDialog(const QList<Author>& allAuthors, QWidget *parent = nullptr);
    ~AddArticleDialog();

    // --- Getters cho Tab 1: Main Details ---
    Type getSelectedType() const;
    QString getTitle() const;
    QString getAbstract() const;
    QString getVenue() const;
    int getYear() const;
    int getCitations() const;
    ArticleStatus getStatus() const;

    // --- Getter cho Tab 2: Authors ---
    /**
     * @brief Lấy danh sách các tác giả đã được chọn cho bài báo này.
     */
    QList<Author> getSelectedAuthors() const;

signals:
    /**
     * @brief Tín hiệu này được phát ra khi người dùng nhấn "Create New Author"
     * và điền xong thông tin. MainWindow nên bắt tín hiệu này và
     * gọi AuthorService để LƯU tác giả mới này vào DB.
     */
    void newAuthorPendingCreation(const Author& newAuthor);

private slots:
    // Slots cho Tab 2 (Authors)
    void onAddAuthorClicked();
    void onRemoveAuthorClicked();
    void onCreateNewAuthorClicked();
    
    // Slot để xác thực dữ liệu
    void validateInput();

private:
    void populateComboBoxes();
    void populateAvailableAuthors();

    Ui::AddArticleDialog *ui;

    // Danh sách để quản lý các đối tượng Author,
    // vì QListWidget chỉ lưu trữ tên (QString)
    QList<Author> m_allAuthors;
    QList<Author> m_selectedAuthors;
};

#endif // ADDARTICLEDIALOG_H