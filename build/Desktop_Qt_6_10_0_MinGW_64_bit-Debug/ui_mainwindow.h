/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblHeader;
    QGroupBox *groupBoxInfo;
    QGridLayout *gridLayout;
    QLabel *label_ProjectName;
    QLabel *label_Student1;
    QLabel *label_PBL;
    QLabel *label_Teacher;
    QFrame *line;
    QLabel *label_Student2;
    QLabel *label_StudentsTitle;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Buttons;
    QPushButton *btnStart;
    QPushButton *btnStop;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lblHeader = new QLabel(centralwidget);
        lblHeader->setObjectName("lblHeader");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(14);
        font.setBold(true);
        lblHeader->setFont(font);
        lblHeader->setStyleSheet(QString::fromUtf8("color: #003366;"));
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lblHeader);

        groupBoxInfo = new QGroupBox(centralwidget);
        groupBoxInfo->setObjectName("groupBoxInfo");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(10);
        groupBoxInfo->setFont(font1);
        gridLayout = new QGridLayout(groupBoxInfo);
        gridLayout->setObjectName("gridLayout");
        label_ProjectName = new QLabel(groupBoxInfo);
        label_ProjectName->setObjectName("label_ProjectName");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(10);
        font2.setBold(true);
        label_ProjectName->setFont(font2);
        label_ProjectName->setStyleSheet(QString::fromUtf8("color: #800000;"));
        label_ProjectName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_ProjectName, 0, 1, 1, 1);

        label_Student1 = new QLabel(groupBoxInfo);
        label_Student1->setObjectName("label_Student1");
        label_Student1->setIndent(15);

        gridLayout->addWidget(label_Student1, 3, 0, 1, 1);

        label_PBL = new QLabel(groupBoxInfo);
        label_PBL->setObjectName("label_PBL");
        label_PBL->setFont(font2);

        gridLayout->addWidget(label_PBL, 0, 0, 1, 1);

        label_Teacher = new QLabel(groupBoxInfo);
        label_Teacher->setObjectName("label_Teacher");
        label_Teacher->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_Teacher, 2, 1, 1, 1);

        line = new QFrame(groupBoxInfo);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        label_Student2 = new QLabel(groupBoxInfo);
        label_Student2->setObjectName("label_Student2");
        label_Student2->setIndent(15);

        gridLayout->addWidget(label_Student2, 4, 0, 1, 1);

        label_StudentsTitle = new QLabel(groupBoxInfo);
        label_StudentsTitle->setObjectName("label_StudentsTitle");

        gridLayout->addWidget(label_StudentsTitle, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBoxInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName("horizontalLayout_Buttons");
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName("btnStart");
        btnStart->setFont(font2);
        btnStart->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnStart);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName("btnStop");
        btnStop->setFont(font2);
        btnStop->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnStop);


        verticalLayout->addLayout(horizontalLayout_Buttons);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c - PBL2", nullptr));
        lblHeader->setText(QCoreApplication::translate("MainWindow", "TR\306\257\341\273\234NG \304\220\341\272\240I H\341\273\214C B\303\201CH KHOA - \304\220\341\272\240I H\341\273\214C \304\220\303\200 N\341\272\264NG", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "Th\303\264ng tin \304\221\341\273\223 \303\241n", nullptr));
        label_ProjectName->setText(QCoreApplication::translate("MainWindow", "X\303\242y d\341\273\261ng \341\273\251ng d\341\273\245ng qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c", nullptr));
        label_Student1->setText(QCoreApplication::translate("MainWindow", "\342\200\242 \304\220\303\240m Ph\303\272 Qu\303\275", nullptr));
        label_PBL->setText(QCoreApplication::translate("MainWindow", "PBL2: D\341\273\261 \303\241n c\306\241 s\341\273\237 l\341\272\255p tr\303\254nh", nullptr));
        label_Teacher->setText(QCoreApplication::translate("MainWindow", "GVHD: \304\220\341\273\227 Th\341\273\213 Tuy\341\272\277t Hoa", nullptr));
        label_Student2->setText(QCoreApplication::translate("MainWindow", "\342\200\242 \304\220\303\240m Vinh Quang", nullptr));
        label_StudentsTitle->setText(QCoreApplication::translate("MainWindow", "Sinh vi\303\252n th\341\273\261c hi\341\273\207n:", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
