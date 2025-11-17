#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "../../../repos/repomanager.h"
#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(RepositoryManager& repo, QWidget *parent = nullptr);
    ~LoginForm();

signals:
    // signal to back
    void requestBack();
    void loginSuccess();

private:
    RepositoryManager& repo;
    Ui::LoginForm *ui;

    void applyStyles();
};

#endif // LOGINFORM_H
