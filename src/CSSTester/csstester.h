#ifndef CSSTESTER_H
#define CSSTESTER_H

#include <QWidget>

namespace Ui {
class CSSTester;
}

class CSSTester : public QWidget
{
    Q_OBJECT

public:
    explicit CSSTester(QWidget *parent = 0);
    ~CSSTester();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private slots:
    void on_refreshCSSBtn_clicked();

    void on_unlockBtn_clicked();

private:
    Ui::CSSTester *ui;
};

#endif // CSSTESTER_H
