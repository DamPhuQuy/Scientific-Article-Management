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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ArticleStatistics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutStats;
    QFrame *frameArticles;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *lblTotalArticles;
    QFrame *frameAuthors;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *lblTotalAuthors;
    QGraphicsView *chartView;

    void setupUi(QDialog *ArticleStatistics)
    {
        if (ArticleStatistics->objectName().isEmpty())
            ArticleStatistics->setObjectName("ArticleStatistics");
        ArticleStatistics->resize(900, 650);
        ArticleStatistics->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5;"));
        verticalLayout = new QVBoxLayout(ArticleStatistics);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        horizontalLayoutStats = new QHBoxLayout();
        horizontalLayoutStats->setSpacing(40);
        horizontalLayoutStats->setObjectName("horizontalLayoutStats");
        frameArticles = new QFrame(ArticleStatistics);
        frameArticles->setObjectName("frameArticles");
        frameArticles->setStyleSheet(QString::fromUtf8("background-color: white; border-radius: 10px; padding: 15px;"));
        frameArticles->setFrameShape(QFrame::StyledPanel);
        frameArticles->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameArticles);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(frameArticles);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        font.setBold(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #7f8c8d;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        lblTotalArticles = new QLabel(frameArticles);
        lblTotalArticles->setObjectName("lblTotalArticles");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(24);
        font1.setBold(true);
        lblTotalArticles->setFont(font1);
        lblTotalArticles->setStyleSheet(QString::fromUtf8("color: #2c3e50;"));
        lblTotalArticles->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblTotalArticles);


        horizontalLayoutStats->addWidget(frameArticles);

        frameAuthors = new QFrame(ArticleStatistics);
        frameAuthors->setObjectName("frameAuthors");
        frameAuthors->setStyleSheet(QString::fromUtf8("background-color: white; border-radius: 10px; padding: 15px;"));
        frameAuthors->setFrameShape(QFrame::StyledPanel);
        frameAuthors->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameAuthors);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(frameAuthors);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: #7f8c8d;"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        lblTotalAuthors = new QLabel(frameAuthors);
        lblTotalAuthors->setObjectName("lblTotalAuthors");
        lblTotalAuthors->setFont(font1);
        lblTotalAuthors->setStyleSheet(QString::fromUtf8("color: #2c3e50;"));
        lblTotalAuthors->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblTotalAuthors);


        horizontalLayoutStats->addWidget(frameAuthors);


        verticalLayout->addLayout(horizontalLayoutStats);

        chartView = new QGraphicsView(ArticleStatistics);
        chartView->setObjectName("chartView");
        chartView->setStyleSheet(QString::fromUtf8("background: transparent; border: none;"));
        chartView->setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        verticalLayout->addWidget(chartView);


        retranslateUi(ArticleStatistics);

        QMetaObject::connectSlotsByName(ArticleStatistics);
    } // setupUi

    void retranslateUi(QDialog *ArticleStatistics)
    {
        ArticleStatistics->setWindowTitle(QCoreApplication::translate("ArticleStatistics", "Article Statistics", nullptr));
        label_2->setText(QCoreApplication::translate("ArticleStatistics", "Total Articles", nullptr));
        lblTotalArticles->setText(QCoreApplication::translate("ArticleStatistics", "0", nullptr));
        label_4->setText(QCoreApplication::translate("ArticleStatistics", "Total Authors", nullptr));
        lblTotalAuthors->setText(QCoreApplication::translate("ArticleStatistics", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArticleStatistics: public Ui_ArticleStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLESTATISTICS_H
