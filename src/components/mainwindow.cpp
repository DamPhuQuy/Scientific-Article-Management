#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect(sender, &SenderClass::signalName, receiver, &ReceiverClass::slotName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked() {
    emit requestStart();
}

void MainWindow::on_btnEnd_clicked() {
    emit requestEnd();
}

