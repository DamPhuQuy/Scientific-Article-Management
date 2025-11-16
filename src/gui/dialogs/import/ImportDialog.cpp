#include "ImportDialog.h"
#include "ui_ImportDialog.h" // File header được Qt tự động tạo ra từ file .ui

#include <QFileDialog>
#include <QMessageBox>

ImportDialog::ImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportDialog)
{
    ui->setupUi(this);
    setWindowTitle("Import Data");

    // Kết nối các nút bấm với các slot xử lý tương ứng
    connect(ui->importJsonButton, &QPushButton::clicked,
            this, &ImportDialog::onImportJsonClicked);

    connect(ui->importAutoButton, &QPushButton::clicked,
            this, &ImportDialog::onImportAutoClicked);

    // Nút "Back" sẽ chỉ đơn giản là đóng dialog (tương đương "Cancel")
    // reject() là một slot có sẵn của QDialog
    connect(ui->backButton, &QPushButton::clicked,
            this, &ImportDialog::reject);
}

ImportDialog::~ImportDialog()
{
    delete ui;
}

// Xử lý khi nhấn nút "Import dataset from JSON"
void ImportDialog::onImportJsonClicked()
{
    // 1. Mở hộp thoại để chọn file articles
    QString articleFile = QFileDialog::getOpenFileName(
        this,
        tr("Select Article JSON Dataset"), // Tiêu đề hộp thoại
        "",                             // Thư mục mặc định
        tr("JSON Files (*.json)")       // Bộ lọc file
    );

    // Nếu người dùng không chọn file (nhấn Cancel)
    if (articleFile.isEmpty()) {
        return; // Không làm gì cả
    }

    // 2. Mở hộp thoại để chọn file authors
    QString authorFile = QFileDialog::getOpenFileName(
        this,
        tr("Select Author JSON Dataset"),
        "",
        tr("JSON Files (*.json)")
    );

    // Nếu người dùng không chọn file
    if (authorFile.isEmpty()) {
        return; // Không làm gì cả
    }

    // 3. Nếu đã có cả 2 file, phát tín hiệu và đính kèm đường dẫn
    emit importFromJsonRequested(articleFile, authorFile);

    // 4. Đóng dialog với trạng thái "Accepted" (thành công)
    accept();
}

// Xử lý khi nhấn nút "Automatically import from system"
void ImportDialog::onImportAutoClicked()
{
    // Chỉ cần phát tín hiệu, không cần lấy file path
    emit importAutoRequested();
    
    // Đóng dialog với trạng thái "Accepted"
    accept();
}