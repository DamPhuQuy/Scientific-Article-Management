#ifndef ARTICLEUPDATE_H
#define ARTICLEUPDATE_H

#include <QDialog>

namespace Ui {
class ArticleUpdate;
}

class ArticleUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleUpdate(QWidget *parent = nullptr);
    ~ArticleUpdate();

signals:
    void requestBack();
    void updateSucces();

private slots:
    void on_btnCancel_clicked();

    void on_btnUpdate_clicked();

private:
    Ui::ArticleUpdate *ui;
};

#endif // ARTICLEUPDATE_H
