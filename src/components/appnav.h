#ifndef APPNAV_H
#define APPNAV_H

#include "src/repos/repomanager.h"
#include <QWidget>
#include <QStackedWidget>

class MainWindow;
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
        MainPage,
        LoginPage,
        SignupPage,
        ArticleFormPage
    };

    void goToHelper(Page page);
    void goTo(Page page);

    void back();

private:
    QStackedWidget* stack;
    std::vector<Page> history;

    MainWindow* mainform;
    LoginForm* login;
    SignUpForm* signup;
    ArticleForm* articleform;
};

#endif // APPNAV_H
