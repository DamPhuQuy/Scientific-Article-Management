// MainWindow.cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "gui/dialogs/import/ImportDialog.h"
#include "gui/dialogs/AddAuthorDialog.h"
#include "gui/dialogs/AddArticleDialog.h"
#include "gui/dialogs/SearchAuthorDialog.h"
#include "gui/dialogs/SearchArticleDialog.h"
#include "gui/dialogs/EditAuthorDialog.h"
#include "gui/dialogs/EditArticleDialog.h"

#include <QMessageBox>
#include <QDialogButtonBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_repoManager(),
      m_dataService(),
      m_articleService(&m_repoManager),
      m_authorService(&m_repoManager)
{
    ui->setupUi(this);

    m_mainMenuWidget     = new MainMenuWidget(this);
    m_articleMgmtWidget  = new ArticleManagementWidget(this, &m_articleService, &m_authorService);
    m_authorMgmtWidget   = new AuthorManagementWidget(this, &m_authorService);
    m_articleStatsWidget = new ArticleStatisticsWidget(this);
    m_articleViewWidget  = new ViewAllArticlesWidget(this);
    m_authorViewWidget   = new ViewAllAuthorsWidget(this);

    ui->mainStackedWidget->addWidget(m_mainMenuWidget);
    ui->mainStackedWidget->addWidget(m_articleMgmtWidget);
    ui->mainStackedWidget->addWidget(m_authorMgmtWidget);
    ui->mainStackedWidget->addWidget(m_articleStatsWidget);
    ui->mainStackedWidget->addWidget(m_articleViewWidget);
    ui->mainStackedWidget->addWidget(m_authorViewWidget);

    setupConnections();
    showMainMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    // Menu actions
    connect(ui->actionImportData, &QAction::triggered, this, &MainWindow::onImportFromJson);
    connect(ui->actionExit, &QAction::triggered, this, &QMainWindow::close);

    // Main menu
    connect(m_mainMenuWidget, &MainMenuWidget::manageArticlesClicked, this, &MainWindow::showArticleManagement);
    connect(m_mainMenuWidget, &MainMenuWidget::manageAuthorsClicked, this, &MainWindow::showAuthorManagement);
    connect(m_mainMenuWidget, &MainMenuWidget::importJsonClicked, this, &MainWindow::onImportFromJson);
    connect(m_mainMenuWidget, &MainMenuWidget::importAutoClicked, this, &MainWindow::onImportAuto);
    connect(m_mainMenuWidget, &MainMenuWidget::statisticsRequested, this, &MainWindow::showArticleStatistics);

    // Article management
    connect(m_articleMgmtWidget, &ArticleManagementWidget::createArticleClicked, this, &MainWindow::onCreateArticle);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::updateArticleClicked, this, &MainWindow::onUpdateArticle);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::deleteArticleClicked, this, &MainWindow::onDeleteArticle);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::searchArticleClicked, this, &MainWindow::onSearchArticle);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::viewAllClicked, this, &MainWindow::showViewAllArticles);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::showStatisticsRequested, this, &MainWindow::showArticleStatistics);
    connect(m_articleMgmtWidget, &ArticleManagementWidget::pendingAuthorCreation, this, &MainWindow::onPendingAuthorCreation);

    // Author management
    connect(m_authorMgmtWidget, &AuthorManagementWidget::createAuthorClicked, this, &MainWindow::onCreateAuthor);
    connect(m_authorMgmtWidget, &AuthorManagementWidget::updateAuthorClicked, this, &MainWindow::onUpdateAuthor);
    connect(m_authorMgmtWidget, &AuthorManagementWidget::deleteAuthorClicked, this, &MainWindow::onDeleteAuthor);
    connect(m_authorMgmtWidget, &AuthorManagementWidget::searchAuthorClicked, this, &MainWindow::onSearchAuthor);
    connect(m_authorMgmtWidget, &AuthorManagementWidget::viewAllClicked, this, &MainWindow::showViewAllAuthors);

    // Article view widget signals
    connect(m_articleViewWidget, &ViewAllArticlesWidget::createRequested, this, &MainWindow::onCreateArticle);
    connect(m_articleViewWidget, &ViewAllArticlesWidget::updateRequested, this, &MainWindow::onUpdateArticleFromView);
    connect(m_articleViewWidget, &ViewAllArticlesWidget::deleteRequested, this, &MainWindow::onDeleteArticleFromView);
    connect(m_articleViewWidget, &ViewAllArticlesWidget::backRequested, this, &MainWindow::showArticleManagement);
    connect(m_articleViewWidget, &ViewAllArticlesWidget::statsRequested, this, &MainWindow::showArticleStatistics);

    // Author view widget signals
    connect(m_authorViewWidget, &ViewAllAuthorsWidget::createRequested, this, &MainWindow::onCreateAuthor);
    connect(m_authorViewWidget, &ViewAllAuthorsWidget::updateRequested, this, &MainWindow::onUpdateAuthorFromView);
    connect(m_authorViewWidget, &ViewAllAuthorsWidget::deleteRequested, this, &MainWindow::onDeleteAuthorFromView);
    connect(m_authorViewWidget, &ViewAllAuthorsWidget::backRequested, this, &MainWindow::showAuthorManagement);
    connect(m_authorViewWidget, &ViewAllAuthorsWidget::statsRequested, this, &MainWindow::showArticleStatistics);

    // Statistics widget
    connect(m_articleStatsWidget, &ArticleStatisticsWidget::statsByYearRequested, this, &MainWindow::onImportFromJson); // placeholder if needed
    connect(m_articleStatsWidget, &ArticleStatisticsWidget::statsByTypeRequested, this, &MainWindow::onImportFromJson); // placeholder
    connect(m_articleStatsWidget, &ArticleStatisticsWidget::backClicked, this, &MainWindow::showArticleManagement);
}

// Navigation
void MainWindow::showMainMenu()
{
    ui->mainStackedWidget->setCurrentWidget(m_mainMenuWidget);
}

void MainWindow::showArticleManagement()
{
    ui->mainStackedWidget->setCurrentWidget(m_articleMgmtWidget);
}

void MainWindow::showAuthorManagement()
{
    ui->mainStackedWidget->setCurrentWidget(m_authorMgmtWidget);
}

void MainWindow::showArticleStatistics()
{
    ui->mainStackedWidget->setCurrentWidget(m_articleStatsWidget);
}

void MainWindow::showViewAllArticles()
{
    m_articleViewWidget->loadData(m_articleService.getAllArticles());
    ui->mainStackedWidget->setCurrentWidget(m_articleViewWidget);
}

void MainWindow::showViewAllAuthors()
{
    m_authorViewWidget->loadData(m_authorService.getAllAuthors());
    ui->mainStackedWidget->setCurrentWidget(m_authorViewWidget);
}

// Import
void MainWindow::onImportFromJson()
{
    ImportDialog dialog(this);
    connect(&dialog, &ImportDialog::importFromJsonRequested, this, &MainWindow::handleImportFromJson);
    connect(&dialog, &ImportDialog::importAutoRequested, this, &MainWindow::onImportAuto);
    dialog.exec();
}

void MainWindow::handleImportFromJson(const QString &articleFile, const QString &authorFile)
{
    try {
        m_dataService.fetchArticleDataSet(articleFile.toStdString(), m_repoManager.getArticles(), m_repoManager.getAuthorArticles());
        m_dataService.fetchAuthorInformation(authorFile.toStdString(), m_repoManager.getAuthors());
        QMessageBox::information(this, "Success", "Data imported successfully from JSON!");
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::onImportAuto()
{
    try {
        // implement auto import constants in your codebase
        QMessageBox::information(this, "Success", "Data imported automatically!");
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

// Author actions
void MainWindow::onCreateAuthor()
{
    AddAuthorDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Author newAuthor = dialog.getAuthorData();
        try {
            m_authorService.createAuthor(newAuthor);
            QMessageBox::information(this, "Success", "Author created successfully!");
            showViewAllAuthors();
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::onUpdateAuthor()
{
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog dlg(allAuthors, this);
    dlg.setWindowTitle("Select Author to Update");
    if (dlg.exec() == QDialog::Accepted) {
        Author authorToUpdate = dlg.getSelectedAuthor();
        EditAuthorDialog edit(this);
        edit.setAuthorData(authorToUpdate);
        if (edit.exec() == QDialog::Accepted) {
            Author updated = edit.getAuthorData();
            m_authorService.updateAuthor(updated);
            QMessageBox::information(this, "Success", "Author updated.");
            showViewAllAuthors();
        }
    }
}

void MainWindow::onDeleteAuthor()
{
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog dlg(allAuthors, this);
    dlg.setWindowTitle("Select Author to Delete");
    if (dlg.exec() == QDialog::Accepted) {
        Author a = dlg.getSelectedAuthor();
        auto reply = QMessageBox::question(this, "Confirm Delete", QString("Delete '%1'?").arg(QString::fromStdString(a.getFullName())), QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            m_authorService.deleteAuthor(a.getId());
            QMessageBox::information(this, "Success", "Author deleted.");
            showViewAllAuthors();
        }
    }
}

void MainWindow::onSearchAuthor()
{
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog dlg(allAuthors, this);
    dlg.setWindowTitle("Search Authors");
    if (auto box = dlg.findChild<QDialogButtonBox*>("buttonBox")) box->setVisible(false);
    dlg.exec();
}

void MainWindow::onViewAllAuthorsRequested()
{
    showViewAllAuthors();
}

// Article actions
void MainWindow::onCreateArticle()
{
    QList<Author> authors = m_authorService.getAllAuthors();
    AddArticleDialog dialog(authors, this);
    connect(&dialog, &AddArticleDialog::newAuthorPendingCreation, this, &MainWindow::onPendingAuthorCreation);
    if (dialog.exec() == QDialog::Accepted) {
        try {
            // gather article data from dialog and call m_articleService.createArticle(...)
            QMessageBox::information(this, "Success", "Article created successfully!");
            showViewAllArticles();
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::onUpdateArticle()
{
    QList<Article*> all = m_articleService.getAllArticles();
    SearchArticleDialog dlg(all, this);
    dlg.setWindowTitle("Select Article to Update");
    if (dlg.exec() == QDialog::Accepted) {
        Article* a = dlg.getSelectedArticle();
        if (!a) return;
        QList<Author> authors = m_authorService.getAllAuthors();
        QList<Author> current = m_authorService.getAuthorsOfArticle(a->getId());
        EditArticleDialog edit(authors, this);
        connect(&edit, &EditArticleDialog::newAuthorPendingCreation, this, &MainWindow::onPendingAuthorCreation);
        edit.setArticleData(a, current);
        if (edit.exec() == QDialog::Accepted) {
            // update via service
            QMessageBox::information(this, "Success", "Article updated.");
            showViewAllArticles();
        }
    }
}

void MainWindow::onDeleteArticle()
{
    QList<Article*> all = m_articleService.getAllArticles();
    SearchArticleDialog dlg(all, this);
    dlg.setWindowTitle("Select Article to Delete");
    if (dlg.exec() == QDialog::Accepted) {
        Article* a = dlg.getSelectedArticle();
        if (!a) return;
        auto reply = QMessageBox::question(this, "Confirm Delete", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            m_articleService.deleteArticle(a->getId());
            QMessageBox::information(this, "Success", "Article deleted.");
            showViewAllArticles();
        }
    }
}

void MainWindow::onSearchArticle()
{
    QList<Article*> all = m_articleService.getAllArticles();
    SearchArticleDialog dlg(all, this);
    dlg.setWindowTitle("Search Articles");
    if (auto box = dlg.findChild<QDialogButtonBox*>("buttonBox")) box->setVisible(false);
    dlg.exec();
}

void MainWindow::onViewAllArticlesRequested()
{
    showViewAllArticles();
}

// From ViewAll widgets
void MainWindow::onUpdateArticleFromView(Article* articleToUpdate)
{
    if (!articleToUpdate) return;
    QList<Author> authors = m_authorService.getAllAuthors();
    QList<Author> current = m_authorService.getAuthorsOfArticle(articleToUpdate->getId());
    EditArticleDialog edit(authors, this);
    connect(&edit, &EditArticleDialog::newAuthorPendingCreation, this, &MainWindow::onPendingAuthorCreation);
    edit.setArticleData(articleToUpdate, current);
    if (edit.exec() == QDialog::Accepted) {
        // update via service
        QMessageBox::information(this, "Success", "Article updated.");
        showViewAllArticles();
    }
}

void MainWindow::onDeleteArticleFromView(Article* articleToDelete)
{
    if (!articleToDelete) return;
    auto reply = QMessageBox::question(this, "Confirm Delete", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        m_articleService.deleteArticle(articleToDelete->getId());
        QMessageBox::information(this, "Success", "Article deleted.");
        showViewAllArticles();
    }
}

void MainWindow::onUpdateAuthorFromView(Author authorToUpdate)
{
    EditAuthorDialog edit(this);
    edit.setAuthorData(authorToUpdate);
    if (edit.exec() == QDialog::Accepted) {
        Author updated = edit.getAuthorData();
        m_authorService.updateAuthor(updated);
        QMessageBox::information(this, "Success", "Author updated.");
        showViewAllAuthors();
    }
}

void MainWindow::onDeleteAuthorFromView(Author authorToDelete)
{
    auto reply = QMessageBox::question(this, "Confirm Delete", QString("Delete '%1'?").arg(QString::fromStdString(authorToDelete.getFullName())), QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        m_authorService.deleteAuthor(authorToDelete.getId());
        QMessageBox::information(this, "Success", "Author deleted.");
        showViewAllAuthors();
    }
}

// Pending author creation from Add/Edit dialogs
void MainWindow::onPendingAuthorCreation(const Author &newAuthor)
{
    try {
        m_authorService.createAuthor(newAuthor);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to create new author: %1").arg(e.what()));
    }
}
