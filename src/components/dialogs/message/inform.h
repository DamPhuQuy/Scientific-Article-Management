#ifndef INFORM_H
#define INFORM_H

#include <QDialog>
#include <QWidget>

enum class MessageType {
    Info,
    Warning
};

class Inform : public QDialog
{
public:
    explicit Inform();

    static void showMessage(QWidget* parent, MessageType type, const QString& text, const QString& title = "Notification");
};

#endif // INFORM_H
