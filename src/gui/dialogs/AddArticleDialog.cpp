#include "AddArticleDialog.h"
#include "ui_AddArticleDialog.h"
#include "dialogs/AddAuthorDialog.h" // Đây là dialog TẠO TÁC GIẢ (tiến trình 5)

#include <QPushButton>
#include <QMessageBox>

AddArticleDialog::AddArticleDialog(const QList<Author>& allAuthors, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddArticleDialog),
    m_allAuthors(allAuthors)
{
    ui->setupUi(this);
    setWindowTitle(tr("Create New Article"));

    populateComboBoxes();
    populateAvailableAuthors();

    // --- Kết nối các nút bấm ---
    connect(ui->addAuthorButton, &QPushButton::clicked,
            this, &AddArticleDialog::onAddAuthorClicked);
    connect(ui->removeAuthorButton, &QPushButton::clicked,
            this, &AddArticleDialog::onRemoveAuthorClicked);
    connect(ui->createNewAuthorButton, &QPushButton::clicked,
            this, &AddArticleDialog::onCreateNewAuthorClicked);

    // --- Xác thực ---
    connect(ui->titleLineEdit, &QLineEdit::textChanged,
            this, &AddArticleDialog::validateInput);
    validateInput(); // Gọi 1 lần để vô hiệu hóa nút OK
}

AddArticleDialog::~AddArticleDialog()
{
    delete ui;
}

void AddArticleDialog::populateComboBoxes()
{
    // Thêm các loại Article Type
    ui->typeComboBox->addItem("SCIE", static_cast<int>(Type::SCIE));
    ui->typeComboBox->addItem("SCOPUS", static_cast<int>(Type::SCOPUS));
    ui->typeComboBox->addItem("CONFERENCE", static_cast<int>(Type::CONFERENCE));
    ui->typeComboBox->addItem("OTHER", static_cast<int>(Type::OTHER));

    // Thêm các trạng thái Status
    ui->statusComboBox->addItem("DRAFT", static_cast<int>(ArticleStatus::DRAFT));
    ui->statusComboBox->addItem("SUBMITTED", static_cast<int>(ArticleStatus::SUBMITTED));
    ui->statusComboBox->addItem("PUBLISHED", static_cast<int>(ArticleStatus::PUBLISHED));
}

void AddArticleDialog::populateAvailableAuthors()
{
    ui->availableAuthorsList->clear();
    for (const Author& author : m_allAuthors) {
        // Chỉ thêm nếu tác giả chưa được chọn
        if (!m_selectedAuthors.contains(author)) {
            QListWidgetItem* item = new QListWidgetItem(author.getFullName());
            item->setData(Qt::UserRole, QVariant::fromValue(author.getId())); // Lưu ID để tham chiếu
            ui->availableAuthorsList->addItem(item);
        }
    }
}

// --- Getters ---

Type AddArticleDialog::getSelectedType() const
{
    return static_cast<Type>(ui->typeComboBox->currentData().toInt());
}

QString AddArticleDialog::getTitle() const { return ui->titleLineEdit->text(); }
QString AddArticleDialog::getAbstract() const { return ui->abstractTextEdit->toPlainText(); }
QString AddArticleDialog::getVenue() const { return ui->venueLineEdit->text(); }
int AddArticleDialog::getYear() const { return ui->yearSpinBox->value(); }
int AddArticleDialog::getCitations() const { return ui->citationsSpinBox->value(); }

ArticleStatus AddArticleDialog::getStatus() const
{
    return static_cast<ArticleStatus>(ui->statusComboBox->currentData().toInt());
}

QList<Author> AddArticleDialog::getSelectedAuthors() const
{
    return m_selectedAuthors;
}

// --- Slots ---

void AddArticleDialog::onAddAuthorClicked()
{
    QListWidgetItem* selectedItem = ui->availableAuthorsList->currentItem();
    if (!selectedItem) return;

    QString selectedId = selectedItem->data(Qt::UserRole).toString();
    
    // Tìm tác giả trong m_allAuthors
    for (const Author& author : m_allAuthors) {
        if (author.getId() == selectedId.toStdString()) {
            m_selectedAuthors.append(author); // Thêm vào danh sách được chọn
            
            // Thêm vào UI list bên phải
            QListWidgetItem* newItem = new QListWidgetItem(author.getFullName());
            newItem->setData(Qt::UserRole, QVariant::fromValue(author.getId()));
            ui->selectedAuthorsList->addItem(newItem);
            
            // Xóa khỏi UI list bên trái
            delete ui->availableAuthorsList->takeItem(ui->availableAuthorsList->row(selectedItem));
            break;
        }
    }
}

void AddArticleDialog::onRemoveAuthorClicked()
{
    QListWidgetItem* selectedItem = ui->selectedAuthorsList->currentItem();
    if (!selectedItem) return;

    QString selectedId = selectedItem->data(Qt::UserRole).toString();

    // Tìm tác giả trong m_selectedAuthors
    for (int i = 0; i < m_selectedAuthors.size(); ++i) {
        if (m_selectedAuthors[i].getId() == selectedId.toStdString()) {
            Author author = m_selectedAuthors.takeAt(i); // Xóa khỏi danh sách được chọn
            
            // Thêm lại vào UI list bên trái
            QListWidgetItem* newItem = new QListWidgetItem(author.getFullName());
            newItem->setData(Qt::UserRole, QVariant::fromValue(author.getId()));
            ui->availableAuthorsList->addItem(newItem);

            // Xóa khỏi UI list bên phải
            delete ui->selectedAuthorsList->takeItem(ui->selectedAuthorsList->row(selectedItem));
            break;
        }
    }
}

void AddArticleDialog::onCreateNewAuthorClicked()
{
    // Gọi dialog của "tiến trình (5)"
    ::AddAuthorDialog authorDialog(this); // Dùng :: để chỉ rõ là class global
    
    if (authorDialog.exec() == QDialog::Accepted) {
        Author newAuthor = authorDialog.getAuthorData(); // Lấy dữ liệu
        
        // Phát tín hiệu yêu cầu MainWindow lưu tác giả này
        // (Service/Repo sẽ tạo ID cho newAuthor)
        emit newAuthorPendingCreation(newAuthor);

        // Tạm thời, chúng ta cũng tự tin thêm vào danh sách
        // (Giả sử MainWindow sẽ xử lý và thành công)
        
        // Thêm vào danh sách quản lý
        m_allAuthors.append(newAuthor); 
        m_selectedAuthors.append(newAuthor);

        // Thêm trực tiếp vào danh sách "Selected" trên UI
        QListWidgetItem* newItem = new QListWidgetItem(newAuthor.getFullName());
        newItem->setData(Qt::UserRole, QVariant::fromValue(QString::fromStdString(newAuthor.getId())));
        ui->selectedAuthorsList->addItem(newItem);

        QMessageBox::information(this, "Author Added", 
            "New author created and added to the 'Selected' list.");
    }
}

void AddArticleDialog::validateInput()
{
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    bool isValid = !ui->titleLineEdit->text().trimmed().isEmpty();
    okButton->setEnabled(isValid);

    // Có thể thêm logic: chuyển sang tab 2 nếu tab 1 đã valid
    // và tab 2 chưa chọn tác giả nào.
    if (!isValid) {
        ui->tabWidget->setCurrentWidget(ui->mainDetailsTab);
    }
}