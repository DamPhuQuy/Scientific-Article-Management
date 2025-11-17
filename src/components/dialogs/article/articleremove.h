#ifndef ARTICLEREMOVE_H
#define ARTICLEREMOVE_H

#include <QDialog>

namespace Ui {
class ArticleRemove;
}

class ArticleRemove : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleRemove(QWidget *parent = nullptr);
    ~ArticleRemove();

private:
    Ui::ArticleRemove *ui;
};

#endif // ARTICLEREMOVE_H
