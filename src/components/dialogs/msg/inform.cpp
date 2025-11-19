#include "inform.h"
#include "qlabel.h"
#include <QMessageBox>
#include <QApplication>

Inform::Inform() {}

void Inform::showMessage(QWidget* parent,
                         MessageType type,
                         const QString& text,
                         const QString& title)
{
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title.isEmpty() ? qApp->applicationName() : title);
    msgBox.setText(text);

    if (QLabel* label = msgBox.findChild<QLabel*>()) {
        label->setWordWrap(true);
        label->setTextInteractionFlags(Qt::TextSelectableByMouse);
        label->setOpenExternalLinks(true);
    }

    // Icon theo loại
    switch (type) {
        case MessageType::Info: msgBox.setIcon(QMessageBox::Information); break;
        case MessageType::Warning:     msgBox.setIcon(QMessageBox::Warning);     break;
        default:                       msgBox.setIcon(QMessageBox::NoIcon);     break;
    }

    QString style = R"(
        QMessageBox {
            background-color: #ffffff;
            border: 1px solid #ddd;
            border-radius: 10px;
        }
        QMessageBox QLabel {
            min-width:  240px;
            max-width:  380px;   /* giới hạn để box không quá rộng */
            font-size: 14px;
            color: #2c3e50;
            padding: 4px;
        }
        QMessageBox QPushButton {
            min-width: 78px;
            min-height: 32px;
            padding: 0px 16px;
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 6px;
            font-size: 13px;
            font-weight: bold;
        }
        QMessageBox QPushButton:hover  { background-color: #2980b9; }
        QMessageBox QPushButton:pressed{ background-color: #1abc9c; }
    )";

    msgBox.setStyleSheet(style);

    msgBox.setMinimumWidth(360);
    msgBox.setMaximumWidth(480);
    msgBox.setSizeGripEnabled(false);

    msgBox.setModal(true);
    msgBox.exec();
}
