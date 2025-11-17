#include "ViewAllAuthorsWidget.h"
#include "ui_ViewAllAuthorsWidget.h"

ViewAllAuthorsWidget::ViewAllAuthorsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewAllAuthorsWidget)
{
    ui->setupUi(this);

    setupTable();
    populateCriteriaComboBox();

    // --- Kết nối các nút bấm ---
    connect(ui->createButton, &QPushButton::clicked, this, &ViewAllAuthorsWidget::onCreateClicked);
    connect(ui->editButton, &QPushButton::clicked, this, &ViewAllAuthorsWidget::onEditClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &ViewAllAuthorsWidget::onDeleteClicked);
    connect(ui->statsButton, &QPushButton::clicked, this, &ViewAllAuthorsWidget::onStatsClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &ViewAllAuthorsWidget::backRequested);

    // --- Kết nối thanh tìm kiếm ---
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &ViewAllAuthorsWidget::onSearchTextChanged);
    connect(ui->criteriaComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ViewAllAuthorsWidget::onCriteriaChanged);

    // --- Kết nối bảng ---
    connect(ui->authorsTableWidget, &QTableWidget::itemSelectionChanged,
            this, &ViewAllAuthorsWidget::onSelectionChanged);
    
    // Bắt đầu với các nút "Edit" và "Delete" bị vô hiệu hóa
    onSelectionChanged();
}

ViewAllAuthorsWidget::~ViewAllAuthorsWidget()
{
    delete ui;
}

void ViewAllAuthorsWidget::setupTable()
{
    // Các cột dựa trên hàm showAuthorDetails()
    ui->authorsTableWidget->setColumnCount(5);
    ui->authorsTableWidget->setHorizontalHeaderLabels({
        "ID", "Full name", "Country", "Field of study", "Total publications"
    });

    // Ẩn cột ID
    ui->authorsTableWidget->setColumnHidden(0, true);
    
    // Tùy chỉnh kích thước cột
    ui->authorsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Name
    ui->authorsTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents); // Country
    ui->authorsTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch); // Field
    ui->authorsTableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents); // Total
}

void ViewAllAuthorsWidget::populateCriteriaComboBox()
{
    // Thay thế AuthorRepo::searchAuthorMenu()
    ui->criteriaComboBox->addItem("Search by Name", 0);
    ui->criteriaComboBox->addItem("Search by Country", 1);
    ui->criteriaComboBox->addItem("Search by Field of Study", 2);
}

void ViewAllAuthorsWidget::loadData(const QList<Author>& allAuthors)
{
    m_allAuthors = allAuthors; // Lưu trữ danh sách đầy đủ
    populateTable(m_allAuthors); // Hiển thị tất cả lên bảng
}

void ViewAllAuthorsWidget::populateTable(const QList<Author>& authors)
{
    ui->authorsTableWidget->setRowCount(0); // Xóa bảng

    for (const Author& author : authors)
    {
        int row = ui->authorsTableWidget->rowCount();
        ui->authorsTableWidget->insertRow(row);

        QString id = QString::fromStdString(author.getId());
        QString name = QString::fromStdString(author.getFullName());
        QString country = QString::fromStdString(author.getCountry());
        QString field = QString::fromStdString(author.getFieldOfStudy());
        QString total = QString::number(author.getTotalPublications());

        // Cột 0: ID (dùng để tra cứu)
        QTableWidgetItem *idItem = new QTableWidgetItem(id);
        ui->authorsTableWidget->setItem(row, 0, idItem);

        ui->authorsTableWidget->setItem(row, 1, new QTableWidgetItem(name));
        ui->authorsTableWidget->setItem(row, 2, new QTableWidgetItem(country));
        ui->authorsTableWidget->setItem(row, 3, new QTableWidgetItem(field));
        ui->authorsTableWidget->setItem(row, 4, new QTableWidgetItem(total));
    }
}

Author ViewAllAuthorsWidget::getSelectedAuthor() const
{
    auto selectedItems = ui->authorsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        return Author(); // Trả về Author rỗng (hoặc xử lý lỗi)
    }

    // Lấy ID từ cột 0 của hàng được chọn
    int selectedRow = selectedItems.first()->row();
    QString selectedId = ui->authorsTableWidget->item(selectedRow, 0)->text();

    // Tìm Author trong danh sách gốc
    for (const Author& author : m_allAuthors) {
        if (QString::fromStdString(author.getId()) == selectedId) {
            return author;
        }
    }
    return Author(); // Không tìm thấy (lỗi)
}

// --- SLOTS ---

void ViewAllAuthorsWidget::onSearchTextChanged(const QString &text)
{
    QList<Author> filteredResults;
    QString lowerText = text.toLower();
    int criteriaIndex = ui->criteriaComboBox->currentData().toInt();

    if (lowerText.isEmpty()) {
        filteredResults = m_allAuthors;
    } else {
        for (const Author& author : m_allAuthors)
        {
            QString searchTarget;
            switch (criteriaIndex)
            {
                case 0: // By Name
                    searchTarget = QString::fromStdString(author.getFullName()).toLower();
                    break;
                case 1: // By Country
                    searchTarget = QString::fromStdString(author.getCountry()).toLower();
                    break;
                case 2: // By Field of Study
                    searchTarget = QString::fromStdString(author.getFieldOfStudy()).toLower();
                    break;
            }
            if (searchTarget.contains(lowerText)) {
                filteredResults.append(author);
            }
        }
    }
    populateTable(filteredResults);
}

void ViewAllAuthorsWidget::onCriteriaChanged(int index)
{
    // Chạy lại tìm kiếm khi đổi tiêu chí
    onSearchTextChanged(ui->searchLineEdit->text());
}

void ViewAllAuthorsWidget::onSelectionChanged()
{
    bool isSelected = !getSelectedAuthor().getId().empty(); // Kiểm tra xem ID có rỗng không
    ui->editButton->setEnabled(isSelected);
    ui->deleteButton->setEnabled(isSelected);
}

// --- SLOTS (Nút bấm) ---

void ViewAllAuthorsWidget::onCreateClicked()
{
    emit createRequested(); // Báo cho MainWindow mở dialog (Tiến trình 5)
}

void ViewAllAuthorsWidget::onEditClicked()
{
    Author selected = getSelectedAuthor();
    if (!selected.getId().empty()) {
        emit updateRequested(selected); // Báo cho MainWindow mở dialog (Tiến trình 9)
    }
}

void ViewAllAuthorsWidget::onDeleteClicked()
{
    Author selected = getSelectedAuthor();
    if (!selected.getId().empty()) {
        emit deleteRequested(selected); // Báo cho MainWindow xử lý xóa
    }
}

void ViewAllAuthorsWidget::onStatsClicked()
{
    emit statsRequested(); // Báo cho MainWindow chuyển trang (Tiến trình 12)
}