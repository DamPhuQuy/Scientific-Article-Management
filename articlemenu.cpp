#include "articlemenu.h"
#include "ui_articlemenu.h"

ArticleMenu::ArticleMenu(RepositoryManager& repo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::articlemenu)
    , repo(repo)
{
    ui->setupUi(this);

    // stackedWidgetInner = new QStackedWidget(this);

    // mainPage = new QWidget();  // Page chính
    // articleInputWidget = new ArticleInput(repo);

    // stackedWidgetInner->addWidget(mainPage);
    // stackedWidgetInner->addWidget(articleInputWidget);

    // stackedWidgetInner->setCurrentWidget(mainPage);

    // connect(articleInputWidget, &ArticleInput::backToMenu, this, &ArticleMenu::articleInputBack);
}

ArticleMenu::~ArticleMenu()
{
    delete ui;
}

void ArticleMenu::setupSignals() {

}
