#ifndef AUTHORINPUTDIALOG_H
#define AUTHORINPUTDIALOG_H

#include <QDialog>
#include "src/models/author.h"

namespace Ui {
class AuthorInputDialog;
}

class AuthorInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorInputDialog(QWidget *parent = nullptr);
    ~AuthorInputDialog();

    Author getAuthor() const;

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::AuthorInputDialog *ui;
    Author author;
    bool validateInputs();
};

#endif // AUTHORINPUTDIALOG_H
