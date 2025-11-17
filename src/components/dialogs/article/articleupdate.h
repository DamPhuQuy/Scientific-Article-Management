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

private:
    Ui::ArticleUpdate *ui;
};

#endif // ARTICLEUPDATE_H
