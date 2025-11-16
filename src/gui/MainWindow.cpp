#include "MainWindow.h"
#include "ui_MainWindow.h"

// Include TẤT CẢ các dialog
#include "gui/dialogs/import/ImportDialog.h"          // Tiến trình (1)
#include "gui/dialogs/AddAuthorDialog.h"        // Tiến trình (5)
#include "gui/dialogs/AddArticleDialog.h"       // Tiến trình (6)
#include "gui/dialogs/SearchAuthorDialog.h"     // Tiến trình (7)
#include "gui/dialogs/SearchArticleDialog.h"    // Tiến trình (8)
#include "gui/dialogs/EditAuthorDialog.h"       // Tiến trình (9)
#include "gui/dialogs/EditArticleDialog.h"      // Tiến trình (10)

// Include Models
#include "models/Author.h"
#include "models/articles/Article.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_repoManager()                 // Repository Manager
    , m_dataService()                 // Import Service
    , m_articleService(&m_repoManager)
    , m_authorService(&m_repoManager)
{
    ui->setupUi(this);

    // ============ 1. TẠO CÁC TRANG ===============
    m_mainMenuWidget = new MainMenuWidget(this);
    m_articleMgmtWidget = new ArticleManagementWidget(this, &m_articleService, &m_authorService);
    m_authorMgmtWidget  = new AuthorManagementWidget(this, &m_authorService);

    // ============ 2. ADD VÀO STACKED WIDGET =======
    ui->mainStackedWidget->addWidget(m_mainMenuWidget);
    ui->mainStackedWidget->addWidget(m_articleMgmtWidget);
    ui->mainStackedWidget->addWidget(m_authorMgmtWidget);

    // ============ 3. CHỌN TRANG MẶC ĐỊNH ==========
    ui->mainStackedWidget->setCurrentWidget(m_mainMenuWidget);

    // ============ 4. KẾT NỐI SIGNAL/SLOT ==========
    setupConnections();

    // ============ 5. KẾT NỐI ACTION MENU BAR ======
    connect(ui->actionImportData, &QAction::triggered,
            this, &MainWindow::on_actionImportData_triggered);

    connect(ui->actionExit, &QAction::triggered,
            this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    // --- Main Menu connections ---
    connect(m_mainMenuWidget, &MainMenuWidget::manageArticlesClicked,
            this, &MainWindow::showArticleManagement);

    connect(m_mainMenuWidget, &MainMenuWidget::manageAuthorsClicked,
            this, &MainWindow::showAuthorManagement);

    connect(m_mainMenuWidget, &MainMenuWidget::exitClicked,
            this, &MainWindow::close);

    // --- Article Management connections (buttons) ---
    connect(m_articleMgmtWidget, &ArticleManagementWidget::createArticleClicked,
            this, &MainWindow::onCreateArticle);

    connect(m_articleMgmtWidget, &ArticleManagementWidget::updateArticleClicked,
            this, &MainWindow::onUpdateArticle);

    connect(m_articleMgmtWidget, &ArticleManagementWidget::deleteArticleClicked,
            this, &MainWindow::onDeleteArticle);

    connect(m_articleMgmtWidget, &ArticleManagementWidget::searchArticleClicked,
            this, &MainWindow::onSearchArticle);

    // Tác giả lồng trong Article Dialog
    connect(m_articleMgmtWidget, &ArticleManagementWidget::pendingAuthorCreation,
            this, &MainWindow::onPendingAuthorCreation);

    // --- Author Management connections ---
    connect(m_authorMgmtWidget, &AuthorManagementWidget::createAuthorClicked,
            this, &MainWindow::onCreateAuthor);

    connect(m_authorMgmtWidget, &AuthorManagementWidget::updateAuthorClicked,
            this, &MainWindow::onUpdateAuthor);

    connect(m_authorMgmtWidget, &AuthorManagementWidget::deleteAuthorClicked,
            this, &MainWindow::onDeleteAuthor);

    connect(m_authorMgmtWidget, &AuthorManagementWidget::searchAuthorClicked,
            this, &MainWindow::onSearchAuthor);
}

// ==========================================================
// SLOTS ĐIỀU HƯỚNG
// ==========================================================
void MainWindow::showMainMenu() {
    if (!ui->mainStackedWidget) {
        qWarning("mainStackedWidget is null!");
        return;
    }
    if (ui->mainStackedWidget->indexOf(m_mainMenuWidget) == -1) {
        qWarning("mainMenuWidget not in mainStackedWidget — adding it dynamically");
        ui->mainStackedWidget->addWidget(m_mainMenuWidget);
    }
    ui->mainStackedWidget->setCurrentWidget(m_mainMenuWidget);
}

void MainWindow::showArticleManagement() {
    if (!ui->mainStackedWidget) { qWarning("mainStackedWidget is null!"); return; }
    if (ui->mainStackedWidget->indexOf(m_articleMgmtWidget) == -1)
        ui->mainStackedWidget->addWidget(m_articleMgmtWidget);
    ui->mainStackedWidget->setCurrentWidget(m_articleMgmtWidget);
}

void MainWindow::showAuthorManagement() {
    if (!ui->mainStackedWidget) { qWarning("mainStackedWidget is null!"); return; }
    if (ui->mainStackedWidget->indexOf(m_authorMgmtWidget) == -1)
        ui->mainStackedWidget->addWidget(m_authorMgmtWidget);
    ui->mainStackedWidget->setCurrentWidget(m_authorMgmtWidget);
}


// ==========================================================
// SLOTS CHO IMPORT (Tiến trình 1)
// ==========================================================
void MainWindow::on_actionImportData_triggered()
{
    ImportDialog dialog(this);
    connect(&dialog, &ImportDialog::importFromJsonRequested,
            this, &MainWindow::handleImportFromJson);
    connect(&dialog, &ImportDialog::importAutoRequested,
            this, &MainWindow::handleImportAuto);
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

void MainWindow::handleImportAuto()
{
    try {
        // (Bạn cần định nghĩa Constants::DataSetJson và Constants::AuInfoJson)
        // m_dataService.fetchArticleDataSet(Constants::DataSetJson, ...);
        // m_dataService.fetchAuthorInformation(Constants::AuInfoJson, ...);
        QMessageBox::information(this, "Success", "Data imported automatically!");
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

// ==========================================================
// SLOTS CHO AUTHOR MANAGEMENT (4, 5, 7, 9)
// ==========================================================
void MainWindow::onCreateAuthor()
{
    AddAuthorDialog dialog(this); // Tiến trình (5)
    if (dialog.exec() == QDialog::Accepted) {
        Author newAuthor = dialog.getAuthorData();
        try {
            m_authorService.createAuthor(newAuthor); // Service tạo ID và lưu
            QMessageBox::information(this, "Success", "Author created successfully!");
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::onUpdateAuthor()
{
    // Bước 1: Chọn Author (Tiến trình 7)
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog searchDialog(allAuthors, this); // Tiến trình (7)
    searchDialog.setWindowTitle("Select Author to Update");

    if (searchDialog.exec() == QDialog::Accepted)
    {
        Author authorToUpdate = searchDialog.getSelectedAuthor();
        
        // Bước 2: Sửa Author (Tiến trình 9)
        EditAuthorDialog editDialog(this); // Tiến trình (9)
        editDialog.setAuthorData(authorToUpdate); 
        
        if (editDialog.exec() == QDialog::Accepted)
        {
            Author updatedAuthor = editDialog.getAuthorData();
            m_authorService.updateAuthor(updatedAuthor); 
            QMessageBox::information(this, "Success", "Author updated.");
        }
    }
}

void MainWindow::onDeleteAuthor()
{
    // Bước 1: Chọn Author (Tiến trình 7)
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog searchDialog(allAuthors, this); // Tiến trình (7)
    searchDialog.setWindowTitle("Select Author to Delete");

    if (searchDialog.exec() == QDialog::Accepted)
    {
        Author authorToDelete = searchDialog.getSelectedAuthor();
        auto reply = QMessageBox::question(this, "Confirm Delete",
            QString("Are you sure you want to delete '%1'?")
                .arg(QString::fromStdString(authorToDelete.getFullName())),
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            m_authorService.deleteAuthor(authorToDelete.getId());
            QMessageBox::information(this, "Success", "Author deleted.");
        }
    }
}

void MainWindow::onSearchAuthor()
{
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    SearchAuthorDialog dialog(allAuthors, this); // Tiến trình (7)
    dialog.setWindowTitle("Search Authors");
    
    // Ẩn nút OK/Cancel, vì đây là chế độ "chỉ xem"
    dialog.findChild<QDialogButtonBox*>("buttonBox")->setVisible(false);
    dialog.exec();
}

void MainWindow::onViewAllAuthors()
{
    // (Bạn cần tạo một widget/dialog mới để hiển thị danh sách)
    QMessageBox::information(this, "View All Authors", "Chức năng này cần một UI (ví dụ: QTableWidget) để hiển thị danh sách tác giả.");
}

// ==========================================================
// SLOTS CHO ARTICLE MANAGEMENT (3, 6, 8, 10)
// ==========================================================
void MainWindow::onCreateArticle()
{
    QList<Author> allAuthors = m_authorService.getAllAuthors();
    AddArticleDialog dialog(allAuthors, this); // Tiến trình (6)
    
    // Kết nối signal nếu tạo author mới từ trong dialog này
    connect(&dialog, &AddArticleDialog::newAuthorPendingCreation,
            this, &MainWindow::onPendingAuthorCreation);

    if (dialog.exec() == QDialog::Accepted)
    {
        try {
            // (Bạn cần mở rộng ArticleService để nhận dữ liệu từ dialog)
            /*
            m_articleService.createArticle(
                dialog.getSelectedType(),
                dialog.getTitle().toStdString(),
                dialog.getAbstract().toStdString(),
                ...
                dialog.getSelectedAuthors()
            );
            */
            QMessageBox::information(this, "Success", "Article created successfully!");
        } catch (const std::exception &e) {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}

void MainWindow::onUpdateArticle()
{
    // Bước 1: Chọn Article (Tiến trình 8)
    QList<Article*> allArticles = m_articleService.getAllArticles();
    SearchArticleDialog searchDialog(allArticles, this); // Tiến trình (8)
    searchDialog.setWindowTitle("Select Article to Update");

    if (searchDialog.exec() == QDialog::Accepted)
    {
        Article* articleToUpdate = searchDialog.getSelectedArticle();
        if (!articleToUpdate) return;
        
        // Bước 2: Lấy tác giả & Sửa Article (Tiến trình 10)
        QList<Author> allAuthors = m_authorService.getAllAuthors();
        QList<Author> currentAuthors = m_authorService.getAuthorsOfArticle(articleToUpdate->getId());

        EditArticleDialog editDialog(allAuthors, this); // Tiến trình (10)
        connect(&editDialog, &EditArticleDialog::newAuthorPendingCreation,
                this, &MainWindow::onPendingAuthorCreation);
        editDialog.setArticleData(articleToUpdate, currentAuthors); 
        
        if (editDialog.exec() == QDialog::Accepted)
        {
            // (Bạn cần mở rộng ArticleService để nhận dữ liệu cập nhật)
            /*
            m_articleService.updateArticle(
                articleToUpdate,
                editDialog.getUpdatedTitle(),
                ...
                editDialog.getUpdatedSelectedAuthors()
            );
            */
            QMessageBox::information(this, "Success", "Article updated.");
        }
    }
}

void MainWindow::onDeleteArticle()
{
    // (Tương tự như onDeleteAuthor, nhưng dùng Tiến trình 8)
    QList<Article*> allArticles = m_articleService.getAllArticles();
    SearchArticleDialog searchDialog(allArticles, this); // Tiến trình (8)
    searchDialog.setWindowTitle("Select Article to Delete");

    if (searchDialog.exec() == QDialog::Accepted)
    {
        Article* articleToDelete = searchDialog.getSelectedArticle();
        if (!articleToDelete) return;

        auto reply = QMessageBox::question(this, "Confirm Delete", "Are you sure?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            m_articleService.deleteArticle(articleToDelete->getId());
            QMessageBox::information(this, "Success", "Article deleted.");
        }
    }
}

void MainWindow::onSearchArticle()
{
    QList<Article*> allArticles = m_articleService.getAllArticles();
    SearchArticleDialog dialog(allArticles, this); // Tiến trình (8)
    dialog.setWindowTitle("Search Articles");
    dialog.findChild<QDialogButtonBox*>("buttonBox")->setVisible(false);
    dialog.exec();
}

void MainWindow::onViewAllArticles()
{
    // (Bạn cần tạo một widget/dialog mới để hiển thị danh sách)
    QMessageBox::information(this, "View All Articles", "Chức năng này cần một UI (ví dụ: QTableWidget) để hiển thị danh sách bài báo.");
}


// ==========================================================
// SLOT HỖ TRỢ
// ==========================================================
void MainWindow::onPendingAuthorCreation(const Author& newAuthor)
{
    // Được gọi bởi Add/Edit Article Dialog
    try {
        m_authorService.createAuthor(newAuthor); 
        // (Không cần thông báo, vì dialog kia sẽ tự xử lý)
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", 
            QString("Failed to create new author: %1").arg(e.what()));
    }
}