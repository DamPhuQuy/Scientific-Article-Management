#ifndef AUTHORREMOVE_H
#define AUTHORREMOVE_H

#include <QDialog>

namespace Ui {
class AuthorRemove;
}

class AuthorRemove : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorRemove(QWidget *parent = nullptr);
    ~AuthorRemove();

private:
    Ui::AuthorRemove *ui;
};

#endif // AUTHORREMOVE_H
