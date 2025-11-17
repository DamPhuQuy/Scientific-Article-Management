#ifndef ARTICLESTATISTICS_H
#define ARTICLESTATISTICS_H

#include <QDialog>

namespace Ui {
class ArticleStatistics;
}

class ArticleStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleStatistics(QWidget *parent = nullptr);
    ~ArticleStatistics();

private:
    Ui::ArticleStatistics *ui;
};

#endif // ARTICLESTATISTICS_H
