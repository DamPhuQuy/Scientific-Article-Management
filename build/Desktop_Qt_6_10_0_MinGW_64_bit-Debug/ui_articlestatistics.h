/********************************************************************************
** Form generated from reading UI file 'articlestatistics.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLESTATISTICS_H
#define UI_ARTICLESTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QHBoxLayout *horizontalLayoutStats;
    QFrame *frameArticles;
    QVBoxLayout *vl_Articles;
    QLabel *lblTitleArticles;
    QLabel *lblTotalArticles;
    QFrame *frameAuthors;
    QVBoxLayout *vl_Authors;
    QLabel *lblTitleAuthors;
    QLabel *lblTotalAuthors;
    QFrame *chartContainer;
    QVBoxLayout *verticalLayout_Chart;
    QGraphicsView *chartView;
    QWidget *footerContainer;
    QHBoxLayout *horizontalLayout_Footer;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QDialog *ArticleStatistics)
    {
        if (ArticleStatistics->objectName().isEmpty())
            ArticleStatistics->setObjectName("ArticleStatistics");
        ArticleStatistics->resize(900, 700);
        ArticleStatistics->setStyleSheet(QString::fromUtf8("QDialog#ArticleStatistics{background-color:#f4f7f6;border:4px solid #FFC085;}QWidget{font-family:\"Segoe UI\",Arial,sans-serif;font-size:14px;}QFrame#frameArticles,QFrame#frameAuthors,QFrame#chartContainer{background-color:#ffffff;border:1px solid #e0e0e0;border-radius:10px;}QLabel#lblTitleArticles,QLabel#lblTitleAuthors{color:#7f8c8d;font-size:13px;font-weight:bold;}QLabel#lblTotalArticles,QLabel#lblTotalAuthors{color:#00264d;font-size:36px;font-weight:bold;}"));
        verticalLayout = new QVBoxLayout(ArticleStatistics);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(ArticleStatistics);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("QWidget#headerContainer{background-color:#00264d;border-bottom:5px solid #4169E1;border-left:10px solid #FFD700;}"));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setStyleSheet(QString::fromUtf8("color:#ffffff;font-weight:900;font-size:20px;background:transparent;padding-left:10px;"));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_Header->addWidget(lblHeader);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(ArticleStatistics);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(20);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 20, 20, 10);
        horizontalLayoutStats = new QHBoxLayout();
        horizontalLayoutStats->setSpacing(20);
        horizontalLayoutStats->setObjectName("horizontalLayoutStats");
        frameArticles = new QFrame(bodyContainer);
        frameArticles->setObjectName("frameArticles");
        frameArticles->setFrameShape(QFrame::Shape::StyledPanel);
        frameArticles->setFrameShadow(QFrame::Shadow::Raised);
        vl_Articles = new QVBoxLayout(frameArticles);
        vl_Articles->setObjectName("vl_Articles");
        lblTitleArticles = new QLabel(frameArticles);
        lblTitleArticles->setObjectName("lblTitleArticles");
        lblTitleArticles->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Articles->addWidget(lblTitleArticles);

        lblTotalArticles = new QLabel(frameArticles);
        lblTotalArticles->setObjectName("lblTotalArticles");
        lblTotalArticles->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Articles->addWidget(lblTotalArticles);


        horizontalLayoutStats->addWidget(frameArticles);

        frameAuthors = new QFrame(bodyContainer);
        frameAuthors->setObjectName("frameAuthors");
        frameAuthors->setFrameShape(QFrame::Shape::StyledPanel);
        frameAuthors->setFrameShadow(QFrame::Shadow::Raised);
        vl_Authors = new QVBoxLayout(frameAuthors);
        vl_Authors->setObjectName("vl_Authors");
        lblTitleAuthors = new QLabel(frameAuthors);
        lblTitleAuthors->setObjectName("lblTitleAuthors");
        lblTitleAuthors->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Authors->addWidget(lblTitleAuthors);

        lblTotalAuthors = new QLabel(frameAuthors);
        lblTotalAuthors->setObjectName("lblTotalAuthors");
        lblTotalAuthors->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vl_Authors->addWidget(lblTotalAuthors);


        horizontalLayoutStats->addWidget(frameAuthors);


        verticalLayout_Body->addLayout(horizontalLayoutStats);

        chartContainer = new QFrame(bodyContainer);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setFrameShape(QFrame::Shape::StyledPanel);
        chartContainer->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_Chart = new QVBoxLayout(chartContainer);
        verticalLayout_Chart->setObjectName("verticalLayout_Chart");
        chartView = new QGraphicsView(chartContainer);
        chartView->setObjectName("chartView");
        chartView->setStyleSheet(QString::fromUtf8("background:transparent;border:none;"));
        chartView->setRenderHints(QPainter::RenderHint::Antialiasing|QPainter::RenderHint::SmoothPixmapTransform|QPainter::RenderHint::TextAntialiasing);

        verticalLayout_Chart->addWidget(chartView);


        verticalLayout_Body->addWidget(chartContainer);


        verticalLayout->addWidget(bodyContainer);

        footerContainer = new QWidget(ArticleStatistics);
        footerContainer->setObjectName("footerContainer");
        horizontalLayout_Footer = new QHBoxLayout(footerContainer);
        horizontalLayout_Footer->setObjectName("horizontalLayout_Footer");
        horizontalLayout_Footer->setContentsMargins(-1, -1, 30, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Footer->addItem(horizontalSpacer);

        closeBtn = new QPushButton(footerContainer);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setMinimumSize(QSize(120, 40));
        closeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#e74c3c;border:2px solid #e74c3c;border-radius:6px;color:white;font-weight:bold;}QPushButton:hover{background-color:#c0392b;}QPushButton:pressed{background-color:#922b21;}"));

        horizontalLayout_Footer->addWidget(closeBtn);


        verticalLayout->addWidget(footerContainer);


        retranslateUi(ArticleStatistics);
        QObject::connect(closeBtn, &QPushButton::clicked, ArticleStatistics, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(ArticleStatistics);
    } // setupUi

    void retranslateUi(QDialog *ArticleStatistics)
    {
        ArticleStatistics->setWindowTitle(QCoreApplication::translate("ArticleStatistics", "Statistics Dashboard", nullptr));
        lblHeader->setText(QCoreApplication::translate("ArticleStatistics", "TH\341\273\220NG K\303\212 D\341\273\256 LI\341\273\206U", nullptr));
        lblTitleArticles->setText(QCoreApplication::translate("ArticleStatistics", "TOTAL ARTICLES", nullptr));
        lblTotalArticles->setText(QCoreApplication::translate("ArticleStatistics", "0", nullptr));
        lblTitleAuthors->setText(QCoreApplication::translate("ArticleStatistics", "TOTAL AUTHORS", nullptr));
        lblTotalAuthors->setText(QCoreApplication::translate("ArticleStatistics", "0", nullptr));
        closeBtn->setText(QCoreApplication::translate("ArticleStatistics", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleStatistics: public Ui_ArticleStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLESTATISTICS_H
