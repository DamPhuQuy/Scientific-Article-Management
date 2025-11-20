#include "authordetailsdialog.h"
#include "ui_authordetailsdialog.h"

using namespace std;

AuthorDetailsDialog::AuthorDetailsDialog(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthorDetailsDialog)
    , repo(repo)
{
    ui->setupUi(this);
}

AuthorDetailsDialog::~AuthorDetailsDialog()
{
    delete ui;
}

void AuthorDetailsDialog::setAuthorInfo(QString id, QString name, QString country, QString field, int pubCount)
{
    ui->labelDetailName->setText(name);

    ui->labelDetailId->setText(id);

    ui->labelDetailCountry->setText(country);
    ui->labelDetailField->setText(field);

    ui->labelDetailPubCount->setText(QString::number(pubCount));
}

void AuthorDetailsDialog::on_okBtn_clicked()
{
    this->accept();
}

