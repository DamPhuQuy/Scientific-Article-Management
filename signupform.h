// signupform.h
#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include <QAction>
#include <QLineEdit>

namespace Ui {
class SignUpLayout;
}

class SignUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
    ~SignUpForm();

signals:
    void backToLogin();

private slots:
    void on_signUpButton_clicked();
    void on_confirmPasswordEdit_textChanged(const QString &text);

private:
    void applyStyles();
    void setupPasswordToggle(QLineEdit *edit);

    Ui::SignUpLayout *ui;
};

#endif
