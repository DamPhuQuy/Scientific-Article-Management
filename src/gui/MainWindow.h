#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList> // Cần cho việc truyền danh sách

// Forward declarations của các lớp UI
namespace Ui {
class MainWindow;
}

// Forward declarations của các Model (để tránh include)
class Author;
class Article;

// Include các Widget "Trang"
#include "gui/widgets/MainMenuWidget.h"
#include "gui/widgets/ArticleManagementWidget.h"
#include "gui/widgets/AuthorManagementWidget.h"

// Include các Services (để thực thi logic)
#include "services/ArticleService.h"
#include "services/AuthorService.h"
#include "services/UserService.h"
#include "utilities/DataManipulation.h" // Cho Import (Tiến trình 1)
#include "repositories/RepositoryManager.h" // Cần cho các service

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // --- Slots điều hướng (chuyển trang StackedWidget) ---
    void showMainMenu();
    void showArticleManagement();
    void showAuthorManagement();
    // (Bạn có thể thêm showStatistics... sau)

    // --- Slot cho Menu Bar (Tiến trình 1) ---
    void on_actionImportData_triggered();
    void handleImportFromJson(const QString &articleFile, const QString &authorFile);
    void handleImportAuto();

    // --- Slots cho Author Management (Tiến trình 4, 5, 7, 9) ---
    void onCreateAuthor();
    void onUpdateAuthor();
    void onDeleteAuthor();
    void onSearchAuthor();
    void onViewAllAuthors(); // (Chưa làm UI, nhưng có thể thêm)

    // --- Slots cho Article Management (Tiến trình 3, 6, 8, 10) ---
    void onCreateArticle();
    void onUpdateArticle();
    void onDeleteArticle();
    void onSearchArticle();
    void onViewAllArticles(); // (Chưa làm UI, nhưng có thể thêm)

    /**
     * @brief Slot đặc biệt, được gọi bởi Add/Edit Article Dialog
     * khi người dùng tạo một tác giả MỚI từ bên trong các dialog đó.
     */
    void onPendingAuthorCreation(const Author& newAuthor);

private:
    /**
     * @brief Hàm helper, gọi 1 lần trong constructor để kết nối TẤT CẢ
     * các signals (từ widget) tới các slots (của MainWindow).
     */
    void setupConnections();

    Ui::MainWindow *ui;

    // --- Các "Trang" chính trong QStackedWidget ---
    MainMenuWidget* m_mainMenuWidget;           // Tiến trình (2)
    ArticleManagementWidget* m_articleMgmtWidget; // Tiến trình (3)
    AuthorManagementWidget* m_authorMgmtWidget;   // Tiến trình (4)
    // Thêm các widget "ViewAll..." hoặc "Statistics..." ở đây

    // --- Các thành phần Lõi (Logic) ---
    // (Giả sử chúng được khởi tạo và truyền vào, hoặc khởi tạo ở đây)
    RepositoryManager m_repoManager; // Khởi tạo Repo Manager
    
    // Khởi tạo các Service
    DataManipulation m_dataService; // Dùng cho Import (Tiến trình 1)
    ArticleService m_articleService;
    AuthorService m_authorService;
    // UserService m_userService; // (Nếu cần cho Login/Register)
};

#endif // MAINWINDOW_H