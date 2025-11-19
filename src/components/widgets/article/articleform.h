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
    void openArticleInputDialog();
    void openArtilceStatisticsDialog();
    void openArticleUpdateArticDialog();
    void openArticleRemoveArticleDialog();

private slots:
    void on_newArticleBtn_clicked();

    void on_statsBtn_clicked();

    void on_updateArtticleBtn_clicked();

    void on_RemoveArticleBtn_clicked();

    void on_searchBtn_clicked();

private:
    RepositoryManager& repo;
    Ui::ArticleForm *ui;
};

#endif // ARTICLEFORM_H
