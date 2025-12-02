#ifndef ARTICLEINPUTDIALOG_H
#define ARTICLEINPUTDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QLineEdit>
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

    void setCurrentUser(const QString& username);

private slots:
    void on_btnSave_clicked();

    void on_btnCancel_clicked();

    void on_inputType_currentIndexChanged(int index);

    void on_AuthorBtn_clicked();

private:
    Ui::ArticleInputDialog *ui;

    QString username;

    RepositoryManager& repo;
    std::vector<std::string> m_selectedAuthorIds;
    QLineEdit* inputCustomTypeName;
};

#endif // ARTICLEINPUTDIALOG_H
