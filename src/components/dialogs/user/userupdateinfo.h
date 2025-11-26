#ifndef USERUPDATEINFO_H
#define USERUPDATEINFO_H

#include <QDialog>
#include <QString>
#include "src/repos/repomanager.h"

namespace Ui {
class userUpdateInfo;
}

class userUpdateInfo : public QDialog
{
    Q_OBJECT

public:
    explicit userUpdateInfo(RepositoryManager& repo, QWidget *parent = nullptr);
    ~userUpdateInfo();

    void loadUserInfo(QString username, QString fullname, QString email, QString phone);

    void setUsername(QString username);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::userUpdateInfo *ui;
    QString m_username;

    RepositoryManager& repo;
};

#endif // USERUPDATEINFO_H
