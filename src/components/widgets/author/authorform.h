#ifndef AUTHORFORM_H
#define AUTHORFORM_H

#include <QWidget>

namespace Ui {
class AuthorForm;
}

class AuthorForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorForm(QWidget *parent = nullptr);
    ~AuthorForm();

private:
    Ui::AuthorForm *ui;
};

#endif // AUTHORFORM_H
