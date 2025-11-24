#include "articleremovedialog.h"
#include "ui_articleremovedialog.h"

articleremovedialog::articleremovedialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::articleremovedialog)
{
    ui->setupUi(this);
}

articleremovedialog::~articleremovedialog()
{
    delete ui;
}
