#include "csstester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CSSTester w;
    w.show();

    return a.exec();
}
