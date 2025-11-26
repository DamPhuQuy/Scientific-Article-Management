#ifndef ARTICLEDETAILSDIALOG_H
#define ARTICLEDETAILSDIALOG_H

#include <QDialog>
#include "qlabel.h"
#include <QListWidgetItem>
#include "src/models/article.h"
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleDetailsDialog;
}

class ArticleDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleDetailsDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleDetailsDialog();

    void setArticleData(Article* article);

private slots:
    void on_btnUpdate_clicked();

    void on_closeBtn_clicked();

    void on_listAuthors_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ArticleDetailsDialog *ui;

    RepositoryManager& repo;

    Article* currentArticle = nullptr;

    QLabel *custom = nullptr;
};

#endif // ARTICLEDETAILSDIALOG_H
