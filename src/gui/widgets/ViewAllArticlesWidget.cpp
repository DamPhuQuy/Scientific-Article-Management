#include "ViewAllArticlesWidget.h"
#include "ui_ViewAllArticlesWidget.h"

ViewAllArticlesWidget::ViewAllArticlesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewAllArticlesWidget)
{
    ui->setupUi(this);

    setupTable();
    populateCriteriaComboBox();

    // --- Kết nối các nút bấm ---
    connect(ui->createButton, &QPushButton::clicked, this, &ViewAllArticlesWidget::onCreateClicked);
    connect(ui->editButton, &QPushButton::clicked, this, &ViewAllArticlesWidget::onEditClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &ViewAllArticlesWidget::onDeleteClicked);
    connect(ui->statsButton, &QPushButton::clicked, this, &ViewAllArticlesWidget::onStatsClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &ViewAllArticlesWidget::backRequested);

    // --- Kết nối thanh tìm kiếm ---
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &ViewAllArticlesWidget::onSearchTextChanged);
    connect(ui->criteriaComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ViewAllArticlesWidget::onCriteriaChanged);

    // --- Kết nối bảng ---
    connect(ui->articlesTableWidget, &QTableWidget::itemSelectionChanged,
            this, &ViewAllArticlesWidget::onSelectionChanged);
    
    // Bắt đầu với các nút "Edit" và "Delete" bị vô hiệu hóa
    onSelectionChanged();
}

ViewAllArticlesWidget::~ViewAllArticlesWidget()
{
    delete ui;
}

void ViewAllArticlesWidget::setupTable()
{
    // Các cột dựa trên hàm showDescription()
    ui->articlesTableWidget->setColumnCount(6);
    ui->articlesTableWidget->setHorizontalHeaderLabels({
        "ID", "Title", "Venue", "Year", "Citations", "Type"
    });

    // Ẩn cột ID, nhưng chúng ta cần nó để tham chiếu
    ui->articlesTableWidget->setColumnHidden(0, true);
    
    // Tùy chỉnh kích thước cột
    ui->articlesTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Title
    ui->articlesTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch); // Venue
    ui->articlesTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Year
    ui->articlesTableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Citations
    ui->articlesTableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents); // Type
}

void ViewAllArticlesWidget::populateCriteriaComboBox()
{
    // Thay thế ArticleRepo::searchMenu()
    ui->criteriaComboBox->addItem("Search by Title", 0);  // index 0
    ui->criteriaComboBox->addItem("Search by Year", 1);   // index 1
    ui->criteriaComboBox->addItem("Search by Type", 2);   // index 2
}

void ViewAllArticlesWidget::loadData(const QList<Article*>& allArticles)
{
    m_allArticles = allArticles; // Lưu trữ danh sách đầy đủ
    populateTable(m_allArticles); // Hiển thị tất cả lên bảng
}

void ViewAllArticlesWidget::populateTable(const QList<Article*>& articles)
{
    ui->articlesTableWidget->setRowCount(0); // Xóa bảng

    for (Article* article : articles)
    {
        int row = ui->articlesTableWidget->rowCount();
        ui->articlesTableWidget->insertRow(row);

        QString id = QString::fromStdString(article->getId());
        QString title = QString::fromStdString(article->getArticleTitle());
        QString venue = QString::fromStdString(article->getVenue());
        QString year = QString::number(article->getYear());
        QString citations = QString::number(article->getNCitation());
        QString type = QString::fromStdString(article->typeToString());

        // Cột 0: ID (dùng để tra cứu)
        QTableWidgetItem *idItem = new QTableWidgetItem(id);
        ui->articlesTableWidget->setItem(row, 0, idItem);

        ui->articlesTableWidget->setItem(row, 1, new QTableWidgetItem(title));
        ui->articlesTableWidget->setItem(row, 2, new QTableWidgetItem(venue));
        ui->articlesTableWidget->setItem(row, 3, new QTableWidgetItem(year));
        ui->articlesTableWidget->setItem(row, 4, new QTableWidgetItem(citations));
        ui->articlesTableWidget->setItem(row, 5, new QTableWidgetItem(type));
    }
}

Article* ViewAllArticlesWidget::getSelectedArticle() const
{
    auto selectedItems = ui->articlesTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        return nullptr;
    }

    // Lấy ID từ cột 0 của hàng được chọn
    int selectedRow = selectedItems.first()->row();
    QString selectedId = ui->articlesTableWidget->item(selectedRow, 0)->text();

    // Tìm con trỏ Article* trong danh sách gốc
    for (Article* article : m_allArticles) {
        if (QString::fromStdString(article->getId()) == selectedId) {
            return article;
        }
    }
    return nullptr;
}

// --- SLOTS ---

void ViewAllArticlesWidget::onSearchTextChanged(const QString &text)
{
    QList<Article*> filteredResults;
    QString lowerText = text.toLower();
    int criteriaIndex = ui->criteriaComboBox->currentData().toInt();

    if (lowerText.isEmpty()) {
        filteredResults = m_allArticles;
    } else {
        for (Article* article : m_allArticles)
        {
            QString searchTarget;
            switch (criteriaIndex)
            {
                case 0: // By Title
                    searchTarget = QString::fromStdString(article->getArticleTitle()).toLower();
                    break;
                case 1: // By Year
                    searchTarget = QString::number(article->getYear());
                    break;
                case 2: // By Type
                    searchTarget = QString::fromStdString(article->typeToString()).toLower();
                    break;
            }
            if (searchTarget.contains(lowerText)) {
                filteredResults.append(article);
            }
        }
    }
    populateTable(filteredResults);
}

void ViewAllArticlesWidget::onCriteriaChanged(int index)
{
    // Chạy lại tìm kiếm khi đổi tiêu chí
    onSearchTextChanged(ui->searchLineEdit->text());
}

void ViewAllArticlesWidget::onSelectionChanged()
{
    bool isSelected = (getSelectedArticle() != nullptr);
    ui->editButton->setEnabled(isSelected);
    ui->deleteButton->setEnabled(isSelected);
}

// --- SLOTS (Nút bấm) ---

void ViewAllArticlesWidget::onCreateClicked()
{
    emit createRequested(); // Báo cho MainWindow mở dialog (Tiến trình 6)
}

void ViewAllArticlesWidget::onEditClicked()
{
    Article* selected = getSelectedArticle();
    if (selected) {
        emit updateRequested(selected); // Báo cho MainWindow mở dialog (Tiến trình 10)
    }
}

void ViewAllArticlesWidget::onDeleteClicked()
{
    Article* selected = getSelectedArticle();
    if (selected) {
        emit deleteRequested(selected); // Báo cho MainWindow xử lý xóa
    }
}

void ViewAllArticlesWidget::onStatsClicked()
{
    emit statsRequested(); // Báo cho MainWindow chuyển trang (Tiến trình 11)
}