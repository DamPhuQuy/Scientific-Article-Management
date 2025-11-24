#ifndef LISTOFAUTHORSDIALOG_H
#define LISTOFAUTHORSDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include "src/repos/repomanager.h"

namespace Ui {
class ListOfAuthorsDialog;
}

class ListOfAuthorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListOfAuthorsDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ListOfAuthorsDialog();

    vector<string> getSelectedAuthorIds() const;
    void setCheckedAuthorIds(const vector<Author> &authors);
signals:
    void requestBack();

private slots:
    void on_listViewAuthors_doubleClicked(const QModelIndex &index);

    void on_btnClose_clicked();

    void on_okBtn_clicked();

    // search and filter
    void on_lineEditSearch_textChanged(const QString &text);
    void on_comboCountry_currentTextChanged(const QString &text);
    void on_comboField_currentTextChanged(const QString &text);
    void on_btnApplyFilter_clicked();

private:
    Ui::ListOfAuthorsDialog *ui;

    RepositoryManager& repo;

    vector<Author> authorList;
    unordered_set<string> preselectedIds;

    QStandardItemModel *model;
    void initData();
    void loadAuthorsToView();
    void loadCountriesToChoose();
    void loadFieldsToChoose();

    QString filterText;
    QString filterCountry;
    QString filterField;
    bool passesAllFilters(int row) const;
    void applyAllFilters();
};

#endif // LISTOFAUTHORSDIALOG_H
