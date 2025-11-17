#ifndef AUTHORUPDATE_H
#define AUTHORUPDATE_H

#include <QDialog>

namespace Ui {
class AuthorUpdate;
}

class AuthorUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorUpdate(QWidget *parent = nullptr);
    ~AuthorUpdate();

private:
    Ui::AuthorUpdate *ui;
};

#endif // AUTHORUPDATE_H
