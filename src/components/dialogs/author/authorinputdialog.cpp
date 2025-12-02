#include "authorinputdialog.h"
#include "ui_authorinputdialog.h"
#include "src/components/dialogs/msg/inform.h"
#include "src/utils/uuid_generator.h"

AuthorInputDialog::AuthorInputDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorInputDialog)
{
    ui->setupUi(this);
}

AuthorInputDialog::~AuthorInputDialog()
{
    delete ui;
}

bool AuthorInputDialog::validateInputs()
{
    if (ui->lineEditName->text().trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning,
                          "Please enter author name!", "Validation Error");
        ui->lineEditName->setFocus();
        return false;
    }

    if (ui->lineEditCountry->text().trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning,
                          "Please enter country!", "Validation Error");
        ui->lineEditCountry->setFocus();
        return false;
    }

    if (ui->lineEditField->text().trimmed().isEmpty()) {
        Inform::showMessage(this, MessageType::Warning,
                          "Please enter field of study!", "Validation Error");
        ui->lineEditField->setFocus();
        return false;
    }

    return true;
}

void AuthorInputDialog::on_btnCancel_clicked()
{
    reject();
}

void AuthorInputDialog::on_btnSave_clicked()
{
    if (!validateInputs()) {
        return;
    }

    // Create author with input data
    author = Author(
        UUID_Generator::generateUUID(),
        ui->lineEditName->text().trimmed().toStdString(),
        ui->lineEditCountry->text().trimmed().toStdString(),
        ui->lineEditField->text().trimmed().toStdString(),
        ui->spinBoxPublications->value()
    );

    accept();
}

Author AuthorInputDialog::getAuthor() const
{
    return author;
}
