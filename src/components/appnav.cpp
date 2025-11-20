#include "appnav.h"
#include "src/components/mainwindow.h"
#include "src/components/widgets/login/loginform.h"
#include "src/components/widgets/login/signupform.h"
#include "src/components/widgets/article/articleform.h"

#include <QVBoxLayout>
#include <QApplication>

AppNav::AppNav(RepositoryManager& repo, QWidget* parent)
    : QWidget(parent), repo(repo)
{
    this->stack = new QStackedWidget(this);

    mainform = new MainWindow(this);
    login = new LoginForm(repo, this);
    signup = new SignUpForm(repo, this);
    articleform = new ArticleForm(repo, this);

    this->stack->addWidget(mainform);    // 0
    this->stack->addWidget(login);       // 1
    this->stack->addWidget(signup);      // 2
    this->stack->addWidget(articleform); // 3

    auto layout = new QVBoxLayout(this);
    layout->addWidget(stack);
    setLayout(layout);

    /* connect(sender, &SenderClass::signalName, receiver, &ReceiverClass::slotName); */ // slotName ở đó là callback
    QString currentUser;

    /* Main Page */
    // start
    connect(mainform, &MainWindow::requestStart, this, [this]() -> void { goTo(Page::LoginPage); });
    // end
    connect(mainform, &MainWindow::requestEnd, this, [this]() -> void { this->history.clear(); qApp->quit(); });

    /* Login Page */
    // requestSignUp
    connect(login, &LoginForm::requestSignUp, this, [this]() -> void { goTo(Page::SignupPage); });
    // login success (loginForm success, go to ArticleForm)
    connect(login, &LoginForm::loginSuccess, this, [this, &currentUser](const QString& username) -> void {
        currentUser = username;
        goTo(Page::ArticleFormPage);
    });
    // request back (loginForm back to mainmenu)
    connect(login, &LoginForm::requestBack, this, [this]() -> void { goTo(Page::MainPage); });

    /* Sign up */
    // sign up success (signUp success, go back to login to login again)
    connect(signup, &SignUpForm::signupSuccess, this, [this]() -> void { goTo(Page::LoginPage); });
    // request back (signupForm back to loginForm)
    connect(signup, &SignUpForm::requestBack, this, [this]() -> void { goTo(Page::LoginPage); });

    /* ArticleForm */
    // request back (articleform back to loginForm)
    connect(articleform, &ArticleForm::requestBack, this, [this]() -> void { goTo(Page::LoginPage); });
}

void AppNav::goToHelper(Page page) {
    switch (page) {
        case MainPage: {
            this->stack->setCurrentWidget(mainform);
            break;
        }
        case LoginPage: {
            this->stack->setCurrentWidget(login);
            break;
        }

        case SignupPage: {
            this->stack->setCurrentWidget(signup);
            break;
        }

        case ArticleFormPage: {
            this->stack->setCurrentWidget(articleform);
            break;
        }
    }
}

void AppNav::goTo(Page page)
{
    Page current = static_cast<Page>(this->stack->currentIndex());
    this->history.push_back(current);

    goToHelper(page);
}

void AppNav::back() {
    if (this->history.size() == 0) {
        return;
    }
    Page last = this->history.at(this->history.size() - 1);
    this->history.pop_back();

    goToHelper(last);
}
