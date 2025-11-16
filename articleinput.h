#ifndef ARTICLEINPUT_H
#define ARTICLEINPUT_H

#include <QWidget>
#include <QDialog>
#include "./src/repos/repomanager.h"

namespace Ui {
class mainDialog;
}

class ArticleInput : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleInput(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleInput();

    QJsonObject getArticleJson() const;

signals:
    void backToMenu();
    void articleAdded();

private slots:

private:
    Ui::mainDialog *ui;
    RepositoryManager& repo;

    void setupSignals();
    void applyStyles();
};

#endif // ARTICLEINPUT_H
