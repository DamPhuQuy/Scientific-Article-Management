#ifndef ARTICLECONFIRMREMOVEDIALOG_H
#define ARTICLECONFIRMREMOVEDIALOG_H

#include <QDialog>
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleConfirmRemoveDialog;
}

class ArticleConfirmRemoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleConfirmRemoveDialog(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleConfirmRemoveDialog();

private:
    RepositoryManager& repo;

    Ui::ArticleConfirmRemoveDialog *ui;
    std::string expectedKey;

public:
    void setExpectedKey(const std::string& key) { expectedKey = key; }

private slots:
    void on_btnRemove_clicked();
    void on_btnCancel_clicked();
};

#endif // ARTICLECONFIRMREMOVEDIALOG_H
