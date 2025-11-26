#include "articleconfirmremovedialog.h"
#include "ui_articleconfirmremovedialog.h"
#include <QMessageBox>

ArticleConfirmRemoveDialog::ArticleConfirmRemoveDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , repo(repo)
    , ui(new Ui::ArticleConfirmRemoveDialog)
{
    ui->setupUi(this);
    connect(ui->btnRemove, &QPushButton::clicked, this, &ArticleConfirmRemoveDialog::on_btnRemove_clicked);
    connect(ui->btnCancel, &QPushButton::clicked, this, &ArticleConfirmRemoveDialog::on_btnCancel_clicked);
}

ArticleConfirmRemoveDialog::~ArticleConfirmRemoveDialog()
{
    delete ui;
}

void ArticleConfirmRemoveDialog::on_btnRemove_clicked()
{
    QString confirmText = ui->editConfirm->text();
    QString keyText = ui->editKey->text();

    qDebug() << "Account key: " << expectedKey;

    if (confirmText != "i confirm") {
        QMessageBox::warning(this, "Invalid Input", "Please type 'i confirm' correctly.");
        return;
    }

    if (keyText.toStdString() != expectedKey) {
        QMessageBox::warning(this, "Invalid Key", "The key provided does not match.");
        return;
    }

    accept();
}

void ArticleConfirmRemoveDialog::on_btnCancel_clicked()
{
    reject();
}
