#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_switchBtn_clicked();
    void timeout();
private:
    Ui::MainWindow *ui;
    bool running = false;
    QTimer timer;
};

#endif // MAINWINDOW_H
