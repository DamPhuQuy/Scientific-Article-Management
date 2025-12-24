#include "src/components/appnav.h"
#include "src/repos/repomanager.h"
#include "src/utils/usermanager.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ArticleRepo a_repo;
    AuthorRepo au_repo;
    UserManager u_manager;
    RepositoryManager repo(a_repo, au_repo, u_manager);
    repo.load();

    // Apply Global Stylesheet
    QString styleSheet = R"(
        * {
            font-family: "Segoe UI";
            color: #2c3e50;
        }
        QMainWindow, QDialog {
            background-color: #f5f5f5;
        }
        QWidget {
            outline: none;
        }

        QLineEdit, QTextEdit, QPlainTextEdit, QSpinBox, QDoubleSpinBox, QComboBox, QDateEdit {
            background-color: white;
            border: 1px solid #bdc3c7;
            border-radius: 5px;
            padding: 5px;
            selection-background-color: #3498db;
            selection-color: white;
        }
        QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus, QSpinBox:focus, QComboBox:focus {
            border: 1px solid #3498db;
        }

        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 5px;
            padding: 8px 15px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1f618d;
        }
        QPushButton:disabled {
            background-color: #bdc3c7;
        }

        QTabWidget::pane {
            border: 1px solid #bdc3c7;
            background: white;
            border-radius: 5px;
        }
        QTabBar::tab {
            background: #ecf0f1;
            border: 1px solid #bdc3c7;
            padding: 8px 12px;
            margin-right: 2px;
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
        }
        QTabBar::tab:selected {
            background: white;
            border-bottom-color: white;
            font-weight: bold;
        }

        QTableWidget, QListWidget, QTreeWidget {
            background-color: white;
            border: 1px solid #bdc3c7;
            border-radius: 5px;
            gridline-color: #ecf0f1;
        }
        QHeaderView::section {
            background-color: #ecf0f1;
            padding: 5px;
            border: none;
            border-right: 1px solid #bdc3c7;
            border-bottom: 1px solid #bdc3c7;
            font-weight: bold;
        }
        QTableWidget::item {
            padding: 5px;
        }
        QTableWidget::item:selected {
            background-color: #3498db;
            color: white;
        }

        QScrollBar:vertical {
            border: none;
            background: #f5f5f5;
            width: 10px;
            margin: 0px 0px 0px 0px;
        }
        QScrollBar::handle:vertical {
            background: #bdc3c7;
            min-height: 20px;
            border-radius: 5px;
        }
        QScrollBar::handle:vertical:hover {
            background: #95a5a6;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }

        QLabel {
            color: #2c3e50;
        }
    )";
    a.setStyleSheet(styleSheet);

    AppNav nav(repo);
    nav.show();

    return a.exec();
}
