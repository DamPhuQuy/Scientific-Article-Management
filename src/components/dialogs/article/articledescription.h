#ifndef ARTICLEDESCRIPTION_H
#define ARTICLEDESCRIPTION_H

#include <QDialog>

namespace Ui {
class ArticleDescription;
}

class ArticleDescription : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleDescription(QWidget *parent = nullptr);
    ~ArticleDescription();

private:
    Ui::ArticleDescription *ui;
};

#endif // ARTICLEDESCRIPTION_H
