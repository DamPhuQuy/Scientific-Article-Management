// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>

namespace Ui { class MainWindow; }

class Author;
class Article;

#include "gui/widgets/MainMenuWidget.h"
#include "gui/widgets/ArticleManagementWidget.h"
#include "gui/widgets/AuthorManagementWidget.h"
#include "gui/widgets/ArticleStatisticsWidget.h"
#include "gui/widgets/ViewAllArticlesWidget.h"
#include "gui/widgets/ViewAllAuthorsWidget.h"

#include "services/ArticleService.h"
#include "services/AuthorService.h"
#include "utilities/DataManipulation.h"
#include "repositories/RepositoryManager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Data manipulation
    void onImportFromJson();
    void onImportAuto();
    void handleImportFromJson(const QString &articleFile, const QString &authorFile);

    // Navigation
    void showMainMenu();
    void showArticleManagement();
    void showAuthorManagement();
    void showArticleStatistics();
    void showViewAllArticles();
    void showViewAllAuthors();

    // Article actions
    void onCreateArticle();
    void onUpdateArticle();
    void onDeleteArticle();
    void onSearchArticle();
    void onViewAllArticlesRequested(); // signal receiver from ArticleManagementWidget

    // Article actions (from ViewAll)
    void onUpdateArticleFromView(Article* articleToUpdate);
    void onDeleteArticleFromView(Article* articleToDelete);

    // Author actions
    void onCreateAuthor();
    void onUpdateAuthor();
    void onDeleteAuthor();
    void onSearchAuthor();
    void onViewAllAuthorsRequested(); // signal receiver from AuthorManagementWidget

    // Author actions (from ViewAll)
    void onUpdateAuthorFromView(Author authorToUpdate);
    void onDeleteAuthorFromView(Author authorToDelete);

    // Pending from dialogs
    void onPendingAuthorCreation(const Author &newAuthor);

private:
    void setupConnections();

private:
    Ui::MainWindow *ui;

    MainMenuWidget* m_mainMenuWidget;
    ArticleManagementWidget* m_articleMgmtWidget;
    AuthorManagementWidget* m_authorMgmtWidget;
    ArticleStatisticsWidget* m_articleStatsWidget;
    ViewAllArticlesWidget* m_articleViewWidget;
    ViewAllAuthorsWidget* m_authorViewWidget;

    RepositoryManager m_repoManager;
    DataManipulation m_dataService;
    ArticleService m_articleService;
    AuthorService m_authorService;
};

#endif // MAINWINDOW_H
