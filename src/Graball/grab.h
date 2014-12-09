#ifndef GRAB_H
#define GRAB_H

#include <QObject>
#include <QThread>
#include <QApplication>
#include <QScreen>
#include <QPixmap>
#include <QFile>
#include <QDir>
#include <QTimer>
class Grab : public QObject
{
    Q_OBJECT
public:
    explicit Grab(QObject *parent = 0);

signals:
    void start(int t);
    void stop();
public slots:
private:
    QThread *thread;
	QTimer *timer;
    bool work = false;
    QList<QPixmap> images;
	int t = 50;
};

#endif // GRAB_H
