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

signals:
    // signal to back
    void requestBack();
    void signupSuccess();

private slots:
    void on_signUpLabel_linkActivated(const QString &link);

    void on_loginLabel_linkActivated(const QString &link);

    void on_signUpButton_clicked();

private:
    RepositoryManager& repo;
    Ui::SignUpForm *ui;

    void applyStyles();
};

#endif // SIGNUPFORM_H
