#ifndef ARTICLEFORM_H
#define ARTICLEFORM_H

#include <QWidget>
#include <QStandardItem>
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
    void openArticleRemoveArticleDialog();

private slots:
    void on_articleListView_doubleClicked(const QModelIndex &index);

    void on_newArticleBtn_clicked();

    void on_RemoveArticleBtn_clicked();

    void on_searchBtn_clicked();

    void on_backBtn_clicked();

    void on_searchLineEdit_textChanged(const QString &arg1);

    void on_yearFilterComboBox_currentTextChanged(const QString &arg1);

    void on_typeFilterComboBox_currentTextChanged(const QString &arg1);

private:
    RepositoryManager& repo;
    Ui::ArticleForm *ui;

    QStandardItemModel* model;

    vector<shared_ptr<Article>> articleList;

    void initData();
    void loadArticlesToView();

    QString filterTitle;
    QString filterYear;
    QString filterType;

    bool passesAllFilters(int row) const;
    void applyYearSorting();
    void applyAllFilters();
};

#endif // ARTICLEFORM_H
