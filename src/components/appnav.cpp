#include "appnav.h"
#include "src/components/widgets/login/loginform.h"
#include "src/components/widgets/login/signupform.h"
#include "src/components/widgets/article/articleform.h"

#include <QVBoxLayout>

AppNav::AppNav(RepositoryManager& repo, QWidget* parent)
    : QWidget(parent), repo(repo)
{
    stack = new QStackedWidget(this);

    login = new LoginForm(repo, this);
    signup = new SignUpForm(repo, this);
    articleform = new ArticleForm(repo, this);

    stack->addWidget(login);       // 0
    stack->addWidget(signup);      // 1
    stack->addWidget(articleform); // 2

    auto layout = new QVBoxLayout(this);
    layout->addWidget(stack);

    // Event: login success
    // connect(login, &LoginForm::loginSuccess, this, [this]() {
    //     goTo(ArticleFormPage);
    // });

    // Event: signup success
    // connect(signup, &SignUpForm::signupSuccess, this, [this]() {
    //     goTo(LoginPage);
    // });
}

void AppNav::goTo(Page page)
{
    stack->setCurrentIndex(static_cast<int>(page));
}
