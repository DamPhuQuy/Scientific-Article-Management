#include "articlestatistics.h"
#include "ui_articlestatistics.h"
#include "src/models/article.h"

ArticleStatistics::ArticleStatistics(RepositoryManager& repo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArticleStatistics)
    , repo(repo)
{
    ui->setupUi(this);
    initStatistics();
}

ArticleStatistics::~ArticleStatistics()
{
    delete ui;
}

void ArticleStatistics::initStatistics()
{
    // fetch data
    int scieCount = repo.getArticles().countByType(Type::SCIE);
    int scopusCount = repo.getArticles().countByType(Type::SCOPUS);
    int conferenceCount = repo.getArticles().countByType(Type::CONFERENCE);
    int customCount = repo.getArticles().countByType(Type::CUSTOM);
    int otherCount = repo.getArticles().countByType(Type::OTHER);

    int totalArticles = scieCount + scopusCount + conferenceCount + customCount + otherCount;
    unsigned int totalAuthors = repo.getAuthors().count();

    // update summary labels
    ui->lblTotalArticles->setText(QString::number(totalArticles));
    ui->lblTotalAuthors->setText(QString::number(totalAuthors));

    // create pie chart
    QPieSeries *series = new QPieSeries();

    
    // check valid data
    if (scieCount > 0) series->append("SCIE", scieCount);
    if (scopusCount > 0) series->append("SCOPUS", scopusCount);
    if (conferenceCount > 0) series->append("Conference", conferenceCount);
    if (customCount > 0) series->append("Custom", customCount);
    if (otherCount > 0) series->append("Other", otherCount);

    // customize slices
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1: %2").arg(slice->label()).arg(slice->value()));
        slice->setPen(QPen(Qt::white, 2)); // White border for separation
    }

    // explode the largest slice for effect
    if (!series->slices().isEmpty()) {
        QPieSlice *largestSlice = nullptr;
        double maxVal = -1;
        for (QPieSlice *slice : series->slices()) {
            if (slice->value() > maxVal) {
                maxVal = slice->value();
                largestSlice = slice;
            }
        }
        if (largestSlice) {
            largestSlice->setExploded(true);
            largestSlice->setLabelVisible(true);
            largestSlice->setExplodeDistanceFactor(0.1);
        }
    }

    // create chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Article Types Distribution");
    chart->setTitleFont(QFont("Segoe UI", 14, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Segoe UI", 10));

    // set chart to view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Replace the placeholder from UI
    if (ui->chartView->parentWidget()->layout()) {
        ui->chartView->parentWidget()->layout()->replaceWidget(ui->chartView, chartView);
        delete ui->chartView;
        ui->chartView = nullptr;
    }
}
