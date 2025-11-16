#include "EditAuthorDialog.h"
#include "ui_EditAuthorDialog.h"

#include <QPushButton>

EditAuthorDialog::EditAuthorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAuthorDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Edit Author"));

    // Kết nối validation (giống hệt AddAuthorDialog)
    connect(ui->fullNameLineEdit, &QLineEdit::textChanged,
            this, &EditAuthorDialog::validateInput);
            
    // Ban đầu, vô hiệu hóa nút OK
    // Nút này sẽ được kích hoạt trong setAuthorData
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

EditAuthorDialog::~EditAuthorDialog()
{
    delete ui;
}

/**
 * @brief Điền dữ liệu của tác giả vào dialog.
 */
void EditAuthorDialog::setAuthorData(const Author& author)
{
    // 1. Lưu ID gốc
    m_authorId = author.getId();

    // 2. Điền dữ liệu vào các trường UI
    ui->fullNameLineEdit->setText(QString::fromStdString(author.getFullName()));
    ui->countryLineEdit->setText(QString::fromStdString(author.getCountry()));
    ui->fieldOfStudyLineEdit->setText(QString::fromStdString(author.getFieldOfStudy()));
    ui->publicationsSpinBox->setValue(author.getTotalPublications());

    // 3. Gọi validateInput() để kiểm tra
    // (Vì tên đã được điền, nút OK sẽ được kích hoạt)
    validateInput();
}

/**
 * @brief Lấy dữ liệu đã cập nhật từ dialog.
 */
Author EditAuthorDialog::getAuthorData() const
{
    Author updatedAuthor;

    // 1. GÁN LẠI ID GỐC (Rất quan trọng)
    updatedAuthor.setId(m_authorId);

    // 2. Lấy dữ liệu đã chỉnh sửa từ các trường UI
    updatedAuthor.setFullName(ui->fullNameLineEdit->text().toStdString());
    updatedAuthor.setCountry(ui->countryLineEdit->text().toStdString());
    updatedAuthor.setFieldOfStudy(ui->fieldOfStudyLineEdit->text().toStdString());
    updatedAuthor.setTotalPublications(ui->publicationsSpinBox->value());

    return updatedAuthor;
}

/**
 * @brief Slot kiểm tra tính hợp lệ của dữ liệu nhập.
 * (Giống hệt AddAuthorDialog)
 */
void EditAuthorDialog::validateInput()
{
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    bool isInputValid = !ui->fullNameLineEdit->text().trimmed().isEmpty();
    okButton->setEnabled(isInputValid);
}