#include "authordetailsdialog.h"
#include "ui_authordetailsdialog.h"

using namespace std;

AuthorDetailsDialog::AuthorDetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorDetailsDialog)
{
    ui->setupUi(this);
}

AuthorDetailsDialog::~AuthorDetailsDialog()
{
    delete ui;
}

void AuthorDetailsDialog::setAuthorInfo(QString id, QString name, QString country, QString field, int pubCount)
{
    // Gán dữ liệu vào các Label tương ứng trong UI
    ui->labelDetailName->setText(name);

    // Chuyển số sang chuỗi bằng QString::number
    ui->labelDetailId->setText(id);

    ui->labelDetailCountry->setText(country);
    ui->labelDetailField->setText(field);

    ui->labelDetailPubCount->setText(QString::number(pubCount));
}

void AuthorDetailsDialog::on_okBtn_clicked()
{
    this->accept();
}

