#ifndef ARTICLEMENU_H
#define ARTICLEMENU_H

#include <QWidget>
#include <QStackedWidget>
#include "articleinput.h"

namespace Ui {
class articlemenu;
}

class ArticleMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleMenu(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleMenu();

signals:
    void backToMainMenu(); // nếu muốn quay lại menu chính

public slots:
    // void openArticleInput();
    // void articleInputBack();

private:
    Ui::articlemenu *ui;

    QStackedWidget *stackedWidgetInner;
    QWidget *mainPage;
    ArticleInput *articleInput;
    RepositoryManager& repo;

    void setupSignals();
};

#endif // ARTICLEMENU_H
