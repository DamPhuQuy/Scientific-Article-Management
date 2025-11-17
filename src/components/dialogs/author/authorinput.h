#ifndef AUTHORINPUT_H
#define AUTHORINPUT_H

#include <QDialog>

namespace Ui {
class AuthorInput;
}

class AuthorInput : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorInput(QWidget *parent = nullptr);
    ~AuthorInput();

private:
    Ui::AuthorInput *ui;
};

#endif // AUTHORINPUT_H
