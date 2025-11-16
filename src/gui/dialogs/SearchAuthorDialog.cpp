#include "SearchAuthorDialog.h"
#include "ui_SearchAuthorDialog.h"

#include <QPushButton>

SearchAuthorDialog::SearchAuthorDialog(const QList<Author>& allAuthors, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchAuthorDialog),
    m_allAuthors(allAuthors)
{
    ui->setupUi(this);
    setWindowTitle(tr("Search and Select Author"));

    setupTable();
    populateCriteriaComboBox();
    populateTable(m_allAuthors); // Hiển thị tất cả lúc đầu

    // --- Kết nối Signals/Slots ---
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &SearchAuthorDialog::onSearchTextChanged);
            
    connect(ui->criteriaComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SearchAuthorDialog::onCriteriaChanged);

    connect(ui->resultsTableWidget, &QTableWidget::itemSelectionChanged,
            this, &SearchAuthorDialog::onRowSelected);

    connect(ui->resultsTableWidget, &QTableWidget::cellDoubleClicked,
            this, &SearchAuthorDialog::onRowDoubleClicked);

    // Vô hiệu hóa nút OK cho đến khi có gì đó được chọn
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

SearchAuthorDialog::~SearchAuthorDialog()
{
    delete ui;
}

void SearchAuthorDialog::setupTable()
{
    ui->resultsTableWidget->setColumnCount(4);
    ui->resultsTableWidget->setHorizontalHeaderLabels({
        "ID", "Full Name", "Country", "Field of Study"
    });
    // Ẩn cột ID, nhưng chúng ta cần nó để lấy dữ liệu
    ui->resultsTableWidget->setColumnHidden(0, true);
    // Tự động kéo giãn cột Tên
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->resultsTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
}

void SearchAuthorDialog::populateCriteriaComboBox()
{
    // Thứ tự phải khớp với logic trong onSearchTextChanged
    ui->criteriaComboBox->addItem("Search by Name");
    ui->criteriaComboBox->addItem("Search by Country");
    ui->criteriaComboBox->addItem("Search by Field of Study");
}

void SearchAuthorDialog::populateTable(const QList<Author>& authors)
{
    ui->resultsTableWidget->setRowCount(0); // Xóa tất cả hàng cũ

    for (const Author& author : authors)
    {
        int row = ui->resultsTableWidget->rowCount();
        ui->resultsTableWidget->insertRow(row);

        // Chuyển đổi std::string sang QString
        QString id = QString::fromStdString(author.getId());
        QString name = QString::fromStdString(author.getFullName());
        QString country = QString::fromStdString(author.getCountry());
        QString field = QString::fromStdString(author.getFieldOfStudy());

        // Cột 0: ID (dùng để tra cứu)
        QTableWidgetItem *idItem = new QTableWidgetItem(id);
        ui->resultsTableWidget->setItem(row, 0, idItem);

        // Cột 1: Name
        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        ui->resultsTableWidget->setItem(row, 1, nameItem);

        // Cột 2: Country
        QTableWidgetItem *countryItem = new QTableWidgetItem(country);
        ui->resultsTableWidget->setItem(row, 2, countryItem);

        // Cột 3: Field of Study
        QTableWidgetItem *fieldItem = new QTableWidgetItem(field);
        ui->resultsTableWidget->setItem(row, 3, fieldItem);
    }
}

Author SearchAuthorDialog::getSelectedAuthor() const
{
    return m_selectedAuthor;
}

// --- SLOTS ---

void SearchAuthorDialog::onSearchTextChanged(const QString &text)
{
    QList<Author> filteredResults;
    QString lowerText = text.toLower(); // Tìm kiếm không phân biệt hoa thường
    int criteriaIndex = ui->criteriaComboBox->currentIndex();

    if (lowerText.isEmpty()) {
        filteredResults = m_allAuthors; // Nếu trống, hiển thị tất cả
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

void SearchAuthorDialog::onCriteriaChanged(int index)
{
    // Khi đổi tiêu chí, chạy lại bộ lọc với văn bản hiện có
    onSearchTextChanged(ui->searchLineEdit->text());
}

void SearchAuthorDialog::onRowSelected()
{
    auto selectedItems = ui->resultsTableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        return;
    }

    // Kích hoạt nút OK
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

    // Lấy ID từ cột 0 (cột ẩn) của hàng được chọn
    int selectedRow = selectedItems.first()->row();
    QString selectedId = ui->resultsTableWidget->item(selectedRow, 0)->text();

    // Tìm đối tượng Author tương ứng trong danh sách gốc
    for (const Author& author : m_allAuthors) {
        if (QString::fromStdString(author.getId()) == selectedId) {
            m_selectedAuthor = author;
            break;
        }
    }
}

void SearchAuthorDialog::onRowDoubleClicked(int row, int column)
{
    // Đảm bảo rằng một tác giả đã được lưu
    onRowSelected();
    
    // Chấp nhận (giống như nhấn OK)
    accept();
}