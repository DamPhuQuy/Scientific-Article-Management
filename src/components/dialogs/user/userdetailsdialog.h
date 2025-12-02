#ifndef USERDETAILSDIALOG_H
#define USERDETAILSDIALOG_H

#include <QDialog>
#include "src/repos/repomanager.h"

namespace Ui {
class UserDetailsDialog;
}

class UserDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDetailsDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~UserDetailsDialog();

    void setUserInfo(QString username, QString fullname, QString email, QString phoneNumber, QString role, QString key);

private slots:
    void on_okBtn_clicked();
    void on_btnUpdate_clicked();

private:
    Ui::UserDetailsDialog *ui;

    RepositoryManager& repo;
};

#endif // USERDETAILSDIALOG_H
