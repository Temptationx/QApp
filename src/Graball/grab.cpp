#include "grab.h"
#include <QUuid>
Grab::Grab(QObject *parent) :
    QObject(parent)
{
    thread = new QThread;
    this->moveToThread(thread);
    thread->start();
	connect(thread, &QThread::started, [this]() {
		timer = new QTimer;
		connect(timer, &QTimer::timeout, this, [this]() {
			if (work){
				images.push_back(QApplication::primaryScreen()->grabWindow(0));
				timer->start(t);
			}
		});
		connect(this, &Grab::start, this, [this](int t_) {
			work = true;
			t = t_ > 0 ? t_ : 50;
			timer->start(t);
		});
		connect(this, &Grab::stop, this, [this]() {
			timer->stop();
			if (work) {
				work = false;
				QDir dir(".");
				dir.mkdir("capture");
				for (QPixmap &image : images){
					image.save(QString("capture/%1.png").arg(QUuid::createUuid().toString()));
				}
				images.clear();
			}

		});
	});

}
