#ifndef AUTHORDETAILSDIALOG_H
#define AUTHORDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class AuthorDetailsDialog;
}

class AuthorDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorDetailsDialog(QWidget *parent = nullptr);
    ~AuthorDetailsDialog();

    void setAuthorInfo(QString, QString name, QString country, QString field, int pubCount);

private slots:
    void on_okBtn_clicked();

private:
    Ui::AuthorDetailsDialog *ui;
};

#endif // AUTHORDETAILSDIALOG_H
