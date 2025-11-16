#include "AddAuthorDialog.h"
#include "ui_AddAuthorDialog.h"

#include <QPushButton> // Cần để bật/tắt nút OK

AddAuthorDialog::AddAuthorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAuthorDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Create New Author"));

    // --- Validation (Xác thực) ---
    // Lấy con trỏ tới nút OK
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    
    // Vô hiệu hóa nút OK ngay từ đầu
    okButton->setEnabled(false);

    // Kết nối sự kiện 'textChanged' của fullNameLineEdit với slot 'validateInput'
    // Bất cứ khi nào người dùng gõ chữ, hàm validateInput sẽ được gọi
    connect(ui->fullNameLineEdit, &QLineEdit::textChanged,
            this, &AddAuthorDialog::validateInput);
}

AddAuthorDialog::~AddAuthorDialog()
{
    delete ui;
}

/**
 * @brief Lấy dữ liệu Author từ các trường UI.
 */
Author AddAuthorDialog::getAuthorData() const
{
    Author newAuthor;

    // Lấy dữ liệu từ QLineEdit/QSpinBox và gán vào đối tượng Author
    // Chuyển đổi từ QString (của Qt) sang std::string (của C++)
    newAuthor.setFullName(ui->fullNameLineEdit->text().toStdString());
    newAuthor.setCountry(ui->countryLineEdit->text().toStdString());
    newAuthor.setFieldOfStudy(ui->fieldOfStudyLineEdit->text().toStdString());
    newAuthor.setTotalPublications(ui->publicationsSpinBox->value());

    // Lưu ý: ID của tác giả (newAuthor.setId(...)) sẽ được tạo
    // bởi AuthorService hoặc AuthorRepo sau khi hàm này trả về,
    // ví dụ: dùng UUID_Generator. Dialog không chịu trách nhiệm tạo ID.

    return newAuthor;
}

/**
 * @brief Slot kiểm tra tính hợp lệ của dữ liệu nhập.
 */
void AddAuthorDialog::validateInput()
{
    // Lấy con trỏ tới nút OK
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);

    // Kiểm tra xem text trong fullNameLineEdit (sau khi đã cắt bỏ
    // khoảng trắng thừa ở 2 đầu) có bị trống hay không.
    bool isInputValid = !ui->fullNameLineEdit->text().trimmed().isEmpty();

    // Bật/tắt nút OK dựa trên kết quả kiểm tra
    okButton->setEnabled(isInputValid);
}