#ifndef ARTICLEINPUT_H
#define ARTICLEINPUT_H

#include <QDialog>

namespace Ui {
class ArticleInput;
}

class ArticleInput : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleInput(QWidget *parent = nullptr);
    ~ArticleInput();

private:
    Ui::ArticleInput *ui;
};

#endif // ARTICLEINPUT_H
