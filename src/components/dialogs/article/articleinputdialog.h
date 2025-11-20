#ifndef ARTICLEINPUTDIALOG_H
#define ARTICLEINPUTDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleInputDialog;
}

class ArticleInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleInputDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleInputDialog();

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

    void on_inputType_currentIndexChanged(int index);

    void on_AuthorBtn_clicked();

private:
    Ui::ArticleInputDialog *ui;

    RepositoryManager& repo;
    std::vector<std::string> m_selectedAuthorIds;
};

#endif // ARTICLEINPUTDIALOG_H
