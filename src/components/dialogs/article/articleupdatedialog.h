#ifndef ARTICLEUPDATEDIALOG_H
#define ARTICLEUPDATEDIALOG_H

#include <QDialog>
#include "src/models/article.h"
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleUpdateDialog;
}

class ArticleUpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleUpdateDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleUpdateDialog();

    void loadData(Article* article);

private slots:
    void on_saveBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::ArticleUpdateDialog *ui;

    RepositoryManager& repo;

    Article* currentArticle = nullptr;
};

#endif // ARTICLEUPDATEDIALOG_H
