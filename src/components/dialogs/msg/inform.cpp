#include "inform.h"
#include <QMessageBox>

Inform::Inform() {}

void Inform::showMessage(QWidget* parent, MessageType type, const QString& text, const QString& title = "Notification") {
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(text);

    QString style = R"(
        QMessageBox {
            background-color: #ffffff;
            border: 1px solid #cccccc;
            border-radius: 8px;
        }
        QMessageBox QLabel {
            min-width: 250px;
            font-size: 14px;
            color: #2c3e50;
        }
        QMessageBox QPushButton {
            min-width: 80px;
            font-size: 13px;
            padding: 4px 8px;
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 4px;
        }
        QMessageBox QPushButton:hover {
            background-color: #2980b9;
        }
        QMessageBox QPushButton:pressed {
            background-color: #1abc9c;
        }
    )";

    msgBox.setStyleSheet(style);

    // Đảm bảo không bị ảnh hưởng bởi parent stylesheet
    msgBox.setModal(true);
    msgBox.exec();
}
