#ifndef AUTHORDESCRIPTION_H
#define AUTHORDESCRIPTION_H

#include <QDialog>

namespace Ui {
class AuthorDescription;
}

class AuthorDescription : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorDescription(QWidget *parent = nullptr);
    ~AuthorDescription();

private:
    Ui::AuthorDescription *ui;
};

#endif // AUTHORDESCRIPTION_H
