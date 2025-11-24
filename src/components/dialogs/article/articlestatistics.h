#ifndef ARTICLESTATISTICS_H
#define ARTICLESTATISTICS_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QPieSeries>
#include <QPieSlice>
#include "src/repos/repomanager.h"

namespace Ui {
class ArticleStatistics;
}

class ArticleStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit ArticleStatistics(RepositoryManager& repo, QWidget *parent = nullptr);
    ~ArticleStatistics();

private:
    Ui::ArticleStatistics *ui;

    RepositoryManager& repo;

    void initStatistics();
};

#endif // ARTICLESTATISTICS_H
