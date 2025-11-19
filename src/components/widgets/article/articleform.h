#ifndef ARTICLEFORM_H
#define ARTICLEFORM_H

#include <QWidget>
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleForm;
}

class ArticleForm : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleForm(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleForm();

signals:
    void requestBack();

private:
    RepositoryManager& repo;
    Ui::ArticleForm *ui;
};

#endif // ARTICLEFORM_H
