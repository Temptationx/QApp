#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qt_windows.h>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeout);
    on_switchBtn_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    POINT pt = {0};
    GetCursorPos(&pt);
    this->setWindowTitle(QString("(%1, %2)").arg(pt.x).arg(pt.y));
}

void MainWindow::on_switchBtn_clicked()
{
    running = !running;
    if(running){
        ui->switchBtn->setText(QStringLiteral("停止"));
        timer.start(15);
    }else{
        ui->switchBtn->setText(QStringLiteral("开始"));
        timer.stop();
    }
}
