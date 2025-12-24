#include "appnav.h"
#include "src/components/mainwindow.h"
#include "src/components/widgets/login/loginform.h"
#include "src/components/widgets/login/signupform.h"
#include "src/components/widgets/article/articleform.h"
#include "src/components/dialogs/msg/inform.h"
#include <QTimer>

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

    connect(mainform, &MainWindow::requestStart, this, [this]() -> void { goTo(Page::LoginPage); });

    connect(mainform, &MainWindow::requestEnd, this, [this]() -> void { this->history.clear(); qApp->quit(); });

    connect(login, &LoginForm::requestSignUp, this, [this]() -> void { goTo(Page::SignupPage); });

    connect(login, &LoginForm::loginSuccess, this,
            [this](const QString& username, const QString& role) {
                currentUser.first = username;
                currentUser.second = role;

                if (!articleform) return;
                articleform->setCurrentUser(currentUser);
                articleform->updateUIAfterLogin();

                goTo(Page::ArticleFormPage);
            });


    connect(login, &LoginForm::requestBack, this, [this]() -> void { goTo(Page::MainPage); });

    connect(signup, &SignUpForm::signupSuccess, this, [this]() -> void { goTo(Page::LoginPage); });

    connect(signup, &SignUpForm::requestBack, this, [this]() -> void { goTo(Page::LoginPage); });

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
