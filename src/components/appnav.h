#ifndef APPNAV_H
#define APPNAV_H

#include "src/repos/repomanager.h"
#include <QWidget>
#include <QStackedWidget>

class LoginForm;
class SignUpForm;
class ArticleForm;

class AppNav : public QWidget
{
    Q_OBJECT

public:
    explicit AppNav(RepositoryManager& repo, QWidget* parent = nullptr);
    RepositoryManager& repo;

    enum Page {
        LoginPage,
        SignupPage,
        ArticleFormPage
    };

    void goTo(Page page);

private:
    QStackedWidget* stack;

    LoginForm* login;
    SignUpForm* signup;
    ArticleForm* articleform;
};

#endif // APPNAV_H
