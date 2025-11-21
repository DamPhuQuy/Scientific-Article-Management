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
    QWidget *containerWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxInfo;
    QGridLayout *gridLayout;
    QLabel *label_PBL;
    QFrame *line;
    QLabel *label_StudentsTitle;
    QLabel *label_Student1;
    QLabel *label_Student2;
    QLabel *label_ProjectName;
    QLabel *label_Teacher;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 500);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    /* === N\341\273\200N CHUNG === */\n"
"    QMainWindow {\n"
"        background-color: #f4f7f6;\n"
"    }\n"
"    QWidget {\n"
"        font-family: \"Segoe UI\", Arial, sans-serif;\n"
"    }\n"
"\n"
"    /* === HEADER TR\306\257\341\273\234NG === */\n"
"    QLabel#lblHeader {\n"
"        background-color: #00264d; /* N\341\273\201n xanh t\341\273\221i \304\221\341\273\203 ch\341\273\257 tr\341\272\257ng n\341\273\225i b\341\272\255t */\n"
"        color: #ffffff;             /* Ch\341\273\257 m\303\240u tr\341\272\257ng */\n"
"        font-size: 20px;\n"
"        font-weight: bold;\n"
"        padding: 20px;              /* Kho\341\272\243ng c\303\241ch \304\221\341\273\207m \304\221\341\273\203 kh\303\264ng \304\221\303\250 ch\341\273\257 */\n"
"        \n"
"        /* \304\220\306\260\341\273\235ng vi\341\273\201n s\341\273\215c v\303\240ng b\303\252n tr\303\241i */\n"
"        border-left: 8px solid #FFD700; \n"
"        \n"
"        /* \304\220\306\260\341\273\235ng k\341\272\273 ngang m\303\240u"
                        " King Blue b\303\252n d\306\260\341\273\233i */\n"
"        border-bottom: 4px solid #4169E1; \n"
"    }\n"
"\n"
"    /* === GROUP BOX === */\n"
"    QGroupBox {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #dcdcdc;\n"
"        border-radius: 8px;\n"
"        margin-top: 30px; /* \304\220\341\273\203 ch\341\273\253a ch\341\273\227 cho title */\n"
"        font-size: 14px;\n"
"    }\n"
"    QGroupBox::title {\n"
"        subcontrol-origin: margin;\n"
"        subcontrol-position: top center;\n"
"        padding: 0 10px;\n"
"        color: #4DB6AC; /* M\303\240u Xanh Ng\341\273\215c Nh\341\272\241t (Jade) */\n"
"        font-weight: bold;\n"
"        font-size: 16px;\n"
"    }\n"
"\n"
"    /* === TEXT STYLES === */\n"
"    /* PBL Title - Xanh ng\341\273\215c */\n"
"    QLabel#label_PBL {\n"
"        color: #20B2AA; /* Jade Green */\n"
"        font-size: 18px;\n"
"        font-weight: bold;\n"
"        text-transform: uppercase;\n"
"    }\n"
"\n"
"    /* Project Name */\n"
"    QLabel#lab"
                        "el_ProjectName {\n"
"        color: #555;\n"
"        font-style: italic;\n"
"        font-size: 15px;\n"
"    }\n"
"\n"
"    /* === HIGHLIGHT PH\341\272\246N GVHD & SV === */\n"
"    QLabel#label_Teacher, QLabel#label_StudentsTitle {\n"
"        color: #B71C1C; /* \304\220\341\273\217 \304\221\341\272\255m \304\221\341\273\203 n\341\273\225i b\341\272\255t vai tr\303\262 */\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"    }\n"
"    \n"
"    /* T\303\252n Sinh vi\303\252n */\n"
"    QLabel#label_Student1, QLabel#label_Student2 {\n"
"        color: #333;\n"
"        font-weight: 600; /* Semi-bold */\n"
"        font-size: 15px;\n"
"        padding: 2px;\n"
"    }\n"
"\n"
"    /* \304\220\306\260\341\273\235ng k\341\272\273 ph\303\242n c\303\241ch m\341\273\235 */\n"
"    Line {\n"
"        color: #dcdcdc;\n"
"    }\n"
"\n"
"    /* === BUTTONS === */\n"
"    QPushButton {\n"
"        background-color: #ffffff;\n"
"        border: 2px solid #4169E1; /* Vi\341\273\201n King Blue */\n"
"        b"
                        "order-radius: 6px;\n"
"        color: #4169E1;\n"
"        padding: 8px 20px;\n"
"        font-weight: bold;\n"
"        font-size: 14px;\n"
"        min-width: 100px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #4169E1;\n"
"        color: white;\n"
"    }\n"
"    QPushButton#btnStop {\n"
"        border-color: #d32f2f;\n"
"        color: #d32f2f;\n"
"    }\n"
"    QPushButton#btnStop:hover {\n"
"        background-color: #d32f2f;\n"
"        color: white;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        lblHeader = new QLabel(centralwidget);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lblHeader);

        containerWidget = new QWidget(centralwidget);
        containerWidget->setObjectName("containerWidget");
        verticalLayout_2 = new QVBoxLayout(containerWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(40, -1, 40, -1);
        groupBoxInfo = new QGroupBox(containerWidget);
        groupBoxInfo->setObjectName("groupBoxInfo");
        gridLayout = new QGridLayout(groupBoxInfo);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(15);
        gridLayout->setContentsMargins(30, 30, 30, 30);
        label_PBL = new QLabel(groupBoxInfo);
        label_PBL->setObjectName("label_PBL");

        gridLayout->addWidget(label_PBL, 0, 0, 1, 1);

        line = new QFrame(groupBoxInfo);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        label_StudentsTitle = new QLabel(groupBoxInfo);
        label_StudentsTitle->setObjectName("label_StudentsTitle");
        label_StudentsTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_StudentsTitle, 2, 0, 1, 1);

        label_Student1 = new QLabel(groupBoxInfo);
        label_Student1->setObjectName("label_Student1");
        label_Student1->setIndent(20);

        gridLayout->addWidget(label_Student1, 3, 0, 1, 1);

        label_Student2 = new QLabel(groupBoxInfo);
        label_Student2->setObjectName("label_Student2");
        label_Student2->setIndent(20);

        gridLayout->addWidget(label_Student2, 4, 0, 1, 1);

        label_ProjectName = new QLabel(groupBoxInfo);
        label_ProjectName->setObjectName("label_ProjectName");
        label_ProjectName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_ProjectName->setWordWrap(true);

        gridLayout->addWidget(label_ProjectName, 0, 1, 1, 1);

        label_Teacher = new QLabel(groupBoxInfo);
        label_Teacher->setObjectName("label_Teacher");
        label_Teacher->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_Teacher, 2, 1, 1, 1);


        verticalLayout_2->addWidget(groupBoxInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setSpacing(20);
        horizontalLayout_Buttons->setObjectName("horizontalLayout_Buttons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer);

        btnStart = new QPushButton(containerWidget);
        btnStart->setObjectName("btnStart");
        btnStart->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnStart);

        btnStop = new QPushButton(containerWidget);
        btnStop->setObjectName("btnStop");
        btnStop->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Buttons->addWidget(btnStop);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_Buttons);


        verticalLayout->addWidget(containerWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c - PBL2", nullptr));
        lblHeader->setText(QCoreApplication::translate("MainWindow", "TR\306\257\341\273\234NG \304\220\341\272\240I H\341\273\214C B\303\201CH KHOA - \304\220\341\272\240I H\341\273\214C \304\220\303\200 N\341\272\264NG", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "TH\303\224NG TIN \304\220\341\273\222 \303\201N", nullptr));
        label_PBL->setText(QCoreApplication::translate("MainWindow", "PBL2: D\341\273\260 \303\201N C\306\240 S\341\273\236 L\341\272\254P TR\303\214NH", nullptr));
        label_StudentsTitle->setText(QCoreApplication::translate("MainWindow", "SINH VI\303\212N TH\341\273\260C HI\341\273\206N:", nullptr));
        label_Student1->setText(QCoreApplication::translate("MainWindow", "1. \304\220\303\240m Ph\303\272 Qu\303\275", nullptr));
        label_Student2->setText(QCoreApplication::translate("MainWindow", "2. \304\220\303\240m Vinh Quang", nullptr));
        label_ProjectName->setText(QCoreApplication::translate("MainWindow", "\"X\303\242y d\341\273\261ng \341\273\251ng d\341\273\245ng qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c\"", nullptr));
        label_Teacher->setText(QCoreApplication::translate("MainWindow", "GVHD: \304\220\341\273\227 Th\341\273\213 Tuy\341\272\277t Hoa", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "B\341\272\256T \304\220\341\272\246U", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "THO\303\201T", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
