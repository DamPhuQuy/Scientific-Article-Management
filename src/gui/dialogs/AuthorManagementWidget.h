#ifndef AUTHORMANAGEMENTWIDGET_H
#define AUTHORMANAGEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class AuthorManagementWidget;
}

class AuthorManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorManagementWidget(QWidget *parent = nullptr);
    ~AuthorManagementWidget();

signals:
    void createAuthorRequested();
    void viewAllAuthorsRequested();
    void updateAuthorRequested();
    void deleteAuthorRequested();
    void searchAuthorsRequested();
    void showStatisticsRequested();
    void backToMainMenuRequested();

private:
    Ui::AuthorManagementWidget *ui;
};

#endif // AUTHORMANAGEMENTWIDGET_H
