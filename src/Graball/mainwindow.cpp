#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g = new Grab;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    emit g->start(ui->timeoutEdit->text().toInt());
}

void MainWindow::on_stopBtn_clicked()
{
    emit g->stop();
}
