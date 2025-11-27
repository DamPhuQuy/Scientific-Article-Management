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
    QWidget *headerContainer;
    QHBoxLayout *horizontalLayout_Header;
    QLabel *lblHeader;
    QWidget *bodyContainer;
    QVBoxLayout *verticalLayout_Body;
    QGroupBox *groupBoxInfo;
    QGridLayout *gridLayout;
    QLabel *label_PBL;
    QLabel *label_ProjectName;
    QFrame *line;
    QLabel *label_StudentsTitle;
    QLabel *label_Teacher;
    QLabel *label_Student1;
    QLabel *label_Student2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_Buttons;
    QPushButton *btnStart;
    QPushButton *btnStop;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(650, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    /* --- MAIN WINDOW --- */\n"
"    QMainWindow {\n"
"        background-color: #f4f7f6; /* N\341\273\201n x\303\241m nh\341\272\241t */\n"
"    }\n"
"\n"
"    /* Vi\341\273\201n cam bao quanh n\341\273\231i dung ch\303\255nh */\n"
"    QWidget#centralwidget {\n"
"        border: 4px solid #FFC085; \n"
"        background-color: #f4f7f6;\n"
"    }\n"
"\n"
"    QWidget { font-family: \"Segoe UI\", Arial, sans-serif; font-size: 14px; }\n"
"\n"
"    /* --- GROUP BOX --- */\n"
"    QGroupBox {\n"
"        background-color: #ffffff;\n"
"        border: 1px solid #e0e0e0;\n"
"        border-radius: 8px;\n"
"        margin-top: 10px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QGroupBox::title {\n"
"        subcontrol-origin: margin;\n"
"        padding: 0 5px;\n"
"        color: #20B2AA; /* M\303\240u xanh ng\341\273\215c c\341\273\247a ti\303\252u \304\221\341\273\201 */\n"
"        font-weight: bold;\n"
"        font-size: 15px;\n"
"        left: 15px; /* Th\341\273\245t \304\221\341\272\247u d\303\262ng"
                        " ti\303\252u \304\221\341\273\201 */\n"
"    }\n"
"    \n"
"    /* --- LABELS --- */\n"
"    QLabel { color: #333; }\n"
"    QLabel#label_ProjectName { color: #c0392b; font-weight: bold; font-size: 15px; }\n"
"    QLabel#label_PBL { color: #00264d; font-weight: bold; }\n"
"    QLabel#label_Teacher, QLabel#label_StudentsTitle { font-weight: bold; color: #555; }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        headerContainer = new QWidget(centralwidget);
        headerContainer->setObjectName("headerContainer");
        headerContainer->setMinimumSize(QSize(0, 70));
        headerContainer->setStyleSheet(QString::fromUtf8("\n"
"        QWidget#headerContainer {\n"
"            background-color: #00264d; /* Xanh \304\221\341\272\255m DUT */\n"
"            border-bottom: 5px solid #4169E1;\n"
"            border-left: 10px solid #FFD700; /* V\341\272\240CH V\303\200NG \304\220\341\272\254M LOGO DUT */\n"
"        }\n"
"       "));
        horizontalLayout_Header = new QHBoxLayout(headerContainer);
        horizontalLayout_Header->setObjectName("horizontalLayout_Header");
        lblHeader = new QLabel(headerContainer);
        lblHeader->setObjectName("lblHeader");
        lblHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblHeader->setStyleSheet(QString::fromUtf8("\n"
"           color: #ffffff;\n"
"           font-weight: 900;\n"
"           font-size: 16px;\n"
"           background: transparent;\n"
"          "));

        horizontalLayout_Header->addWidget(lblHeader);


        verticalLayout->addWidget(headerContainer);

        bodyContainer = new QWidget(centralwidget);
        bodyContainer->setObjectName("bodyContainer");
        verticalLayout_Body = new QVBoxLayout(bodyContainer);
        verticalLayout_Body->setSpacing(20);
        verticalLayout_Body->setObjectName("verticalLayout_Body");
        verticalLayout_Body->setContentsMargins(20, 20, 20, 10);
        groupBoxInfo = new QGroupBox(bodyContainer);
        groupBoxInfo->setObjectName("groupBoxInfo");
        gridLayout = new QGridLayout(groupBoxInfo);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(15);
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setContentsMargins(20, 35, 20, 20);
        label_PBL = new QLabel(groupBoxInfo);
        label_PBL->setObjectName("label_PBL");

        gridLayout->addWidget(label_PBL, 0, 0, 1, 1);

        label_ProjectName = new QLabel(groupBoxInfo);
        label_ProjectName->setObjectName("label_ProjectName");
        label_ProjectName->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_ProjectName->setWordWrap(true);

        gridLayout->addWidget(label_ProjectName, 0, 1, 1, 1);

        line = new QFrame(groupBoxInfo);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line->setStyleSheet(QString::fromUtf8("color: #cccccc;"));

        gridLayout->addWidget(line, 1, 0, 1, 2);

        label_StudentsTitle = new QLabel(groupBoxInfo);
        label_StudentsTitle->setObjectName("label_StudentsTitle");

        gridLayout->addWidget(label_StudentsTitle, 2, 0, 1, 1);

        label_Teacher = new QLabel(groupBoxInfo);
        label_Teacher->setObjectName("label_Teacher");
        label_Teacher->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(label_Teacher, 2, 1, 1, 1);

        label_Student1 = new QLabel(groupBoxInfo);
        label_Student1->setObjectName("label_Student1");
        label_Student1->setIndent(20);

        gridLayout->addWidget(label_Student1, 3, 0, 1, 2);

        label_Student2 = new QLabel(groupBoxInfo);
        label_Student2->setObjectName("label_Student2");
        label_Student2->setIndent(20);

        gridLayout->addWidget(label_Student2, 4, 0, 1, 2);


        verticalLayout_Body->addWidget(groupBoxInfo);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_Body->addItem(verticalSpacer);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setSpacing(30);
        horizontalLayout_Buttons->setObjectName("horizontalLayout_Buttons");
        btnStart = new QPushButton(bodyContainer);
        btnStart->setObjectName("btnStart");
        btnStart->setMinimumSize(QSize(150, 50));
        btnStart->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnStart->setStyleSheet(QString::fromUtf8("\n"
"             QPushButton {\n"
"              background-color: #20B2AA; \n"
"              border: 2px solid #20B2AA;\n"
"              border-radius: 8px; \n"
"              color: white; \n"
"              font-weight: bold;\n"
"              font-size: 15px;\n"
"             }\n"
"             QPushButton:hover { background-color: #17a098; border-color: #17a098; }\n"
"             QPushButton:pressed { background-color: #0e6b65; }\n"
"            "));

        horizontalLayout_Buttons->addWidget(btnStart);

        btnStop = new QPushButton(bodyContainer);
        btnStop->setObjectName("btnStop");
        btnStop->setMinimumSize(QSize(150, 50));
        btnStop->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnStop->setStyleSheet(QString::fromUtf8("\n"
"             QPushButton {\n"
"              background-color: #e74c3c; \n"
"              border: 2px solid #e74c3c;\n"
"              border-radius: 8px; \n"
"              color: white; \n"
"              font-weight: bold;\n"
"              font-size: 15px;\n"
"             }\n"
"             QPushButton:hover { background-color: #c0392b; border-color: #c0392b; }\n"
"             QPushButton:pressed { background-color: #922b21; }\n"
"            "));

        horizontalLayout_Buttons->addWidget(btnStop);


        verticalLayout_Body->addLayout(horizontalLayout_Buttons);


        verticalLayout->addWidget(bodyContainer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(btnStop, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c - PBL2", nullptr));
        lblHeader->setText(QCoreApplication::translate("MainWindow", "TR\306\257\341\273\234NG \304\220\341\272\240I H\341\273\214C B\303\201CH KHOA - \304\220\341\272\240I H\341\273\214C \304\220\303\200 N\341\272\264NG", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", " TH\303\224NG TIN \304\220\341\273\222 \303\201N ", nullptr));
        label_PBL->setText(QCoreApplication::translate("MainWindow", "PBL2: D\341\273\261 \303\241n c\306\241 s\341\273\237 l\341\272\255p tr\303\254nh", nullptr));
        label_ProjectName->setText(QCoreApplication::translate("MainWindow", "X\303\242y d\341\273\261ng \341\273\251ng d\341\273\245ng qu\341\272\243n l\303\275 b\303\240i b\303\241o khoa h\341\273\215c", nullptr));
        label_StudentsTitle->setText(QCoreApplication::translate("MainWindow", "Sinh vi\303\252n th\341\273\261c hi\341\273\207n:", nullptr));
        label_Teacher->setText(QCoreApplication::translate("MainWindow", "GVHD: \304\220\341\273\227 Th\341\273\213 Tuy\341\272\277t Hoa", nullptr));
        label_Student1->setText(QCoreApplication::translate("MainWindow", "\342\200\242 \304\220\303\240m Ph\303\272 Qu\303\275", nullptr));
        label_Student2->setText(QCoreApplication::translate("MainWindow", "\342\200\242 \304\220\303\240m Vinh Quang", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
