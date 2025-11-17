#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include "src/repos/repomanager.h"

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(RepositoryManager& repo, QWidget *parent = nullptr);
    ~SignUpForm();

private:
    RepositoryManager& repo;
    Ui::SignUpForm *ui;
};

#endif // SIGNUPFORM_H
