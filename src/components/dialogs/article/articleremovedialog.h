#ifndef ARTICLEREMOVEDIALOG_H
#define ARTICLEREMOVEDIALOG_H

#include <QDialog>

namespace Ui {
class articleremovedialog;
}

class articleremovedialog : public QDialog
{
    Q_OBJECT

public:
    explicit articleremovedialog(QWidget *parent = nullptr);
    ~articleremovedialog();

private:
    Ui::articleremovedialog *ui;
};

#endif // ARTICLEREMOVEDIALOG_H
