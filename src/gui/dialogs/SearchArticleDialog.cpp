#include "SearchArticleDialog.h"
#include "ui_SearchArticleDialog.h"

#include <QPushButton>

SearchArticleDialog::SearchArticleDialog(const QList<Article*>& allArticles, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchArticleDialog),
    m_allArticles(allArticles),
    m_selectedArticle(nullptr)
{
    ui->setupUi(this);
    setWindowTitle(tr("Search and Select Article"));

    setupTable();
    populateCriteriaComboBox();
    populateTable(m_allArticles); // Hiển thị tất cả lúc đầu

    // --- Kết nối Signals/Slots ---
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &SearchArticleDialog::onSearchTextChanged);
            
    connect(ui->criteriaComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SearchArticleDialog::onCriteriaChanged);

    connect(ui->resultsTableWidget, &QTableWidget::itemSelectionChanged,
            this, &SearchArticleDialog::onRowSelected);

    connect(ui->resultsTableWidget, &QTableWidget::cellDoubleClicked,
            this, &SearchArticleDialog::onRowDoubleClicked);

    // Vô hiệu hóa nút OK
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

SearchArticleDialog::~SearchArticleDialog()
{
    delete ui;
}

void SearchArticleDialog::setupTable()
{
    ui->resultsTableWidget->setColumnCount(5);
    ui->resultsTableWidget->setHorizontalHeaderLabels({
        "ID", "Title", "Year", "Type", "Venue"
    });
    // Ẩn cột ID, nhưng chúng ta cần nó
    ui->resultsTableWidget->setColumnHidden(0, true);
    
    // Tự động kéo giãn cột
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Title
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Year
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); // Type
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch); // Venue
}

void SearchArticleDialog::populateCriteriaComboBox()
{
    // Thứ tự phải khớp với logic trong onSearchTextChanged
    ui->criteriaComboBox->addItem("Search by Title");  // index 0
    ui->criteriaComboBox->addItem("Search by Year");   // index 1
    ui->criteriaComboBox->addItem("Search by Type");   // index 2
}

void SearchArticleDialog::populateTable(const QList<Article*>& articles)
{
    ui->resultsTableWidget->setRowCount(0); // Xóa bảng

    for (Article* article : articles)
    {
        int row = ui->resultsTableWidget->rowCount();
        ui->resultsTableWidget->insertRow(row);

        // Chuyển đổi std::string sang QString
        QString id = QString::fromStdString(article->getId());
        QString title = QString::fromStdString(article->getArticleTitle());
        QString year = QString::number(article->getYear());
        QString type = QString::fromStdString(article->typeToString());
        QString venue = QString::fromStdString(article->getVenue());

        // Cột 0: ID (dùng để tra cứu)
        QTableWidgetItem *idItem = new QTableWidgetItem(id);
        ui->resultsTableWidget->setItem(row, 0, idItem);

        ui->resultsTableWidget->setItem(row, 1, new QTableWidgetItem(title));
        ui->resultsTableWidget->setItem(row, 2, new QTableWidgetItem(year));
        ui->resultsTableWidget->setItem(row, 3, new QTableWidgetItem(type));
        ui->resultsTableWidget->setItem(row, 4, new QTableWidgetItem(venue));
    }
}

Article* SearchArticleDialog::getSelectedArticle() const
{
    return m_selectedArticle;
}

// --- SLOTS ---

void SearchArticleDialog::onSearchTextChanged(const QString &text)
{
    QList<Article*> filteredResults;
    QString lowerText = text.toLower();
    int criteriaIndex = ui->criteriaComboBox->currentIndex();

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

void SearchArticleDialog::onCriteriaChanged(int index)
{
    onSearchTextChanged(ui->searchLineEdit->text());
}

void SearchArticleDialog::onRowSelected()
{
    auto selectedItems = ui->resultsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        m_selectedArticle = nullptr;
        return;
    }

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

    // Lấy ID từ cột 0
    int selectedRow = selectedItems.first()->row();
    QString selectedId = ui->resultsTableWidget->item(selectedRow, 0)->text();

    // Tìm con trỏ Article* tương ứng
    for (Article* article : m_allArticles) {
        if (QString::fromStdString(article->getId()) == selectedId) {
            m_selectedArticle = article;
            break;
        }
    }
}

void SearchArticleDialog::onRowDoubleClicked(int row, int column)
{
    onRowSelected();
    if (m_selectedArticle) {
        accept(); // Chấp nhận dialog
    }
}