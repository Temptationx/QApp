#include "csstester.h"
#include "ui_csstester.h"
#include <QShortcut>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QUrl>
CSSTester::CSSTester(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSSTester)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    QShortcut *s = new QShortcut(this);
    s->setKey(QKeySequence("Ctrl+S"));
    connect(s, &QShortcut::activated, this, &CSSTester::on_refreshCSSBtn_clicked);
}

CSSTester::~CSSTester()
{
    delete ui;
}

void CSSTester::on_refreshCSSBtn_clicked()
{
    QFile file(ui->fileEdit->text());
    file.open(QIODevice::ReadOnly);
    auto content = file.readAll();
    ui->widget->setStyleSheet(QString(content) + ui->cssEdit->document()->toPlainText());
}

void CSSTester::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
    }
}

void CSSTester::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls()){
       auto urls = event->mimeData()->urls();
       for(auto url : urls){
           QFileInfo info(url.toLocalFile());
           if(info.suffix() == "css"){
               ui->fileEdit->setText(info.absoluteFilePath());
               on_refreshCSSBtn_clicked();
           }
       }
    }
}

void CSSTester::on_unlockBtn_clicked()
{
    ui->disabledWidgetFrame->setEnabled(!ui->disabledWidgetFrame->isEnabled());
}
