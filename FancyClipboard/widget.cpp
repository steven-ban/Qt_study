#include "widget.h"
#include "ui_widget.h"

#include<QClipboard>
#include<QApplication>
#include<QDebug>
#include<QMessageBox>
#include<QMimeData>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    clipBrd = QApplication::clipboard();

    connect(clipBrd, SIGNAL(dataChanged()), this, SLOT(appendClip()));
    connect(ui->helpButton, SIGNAL(clicked()), this, SLOT(showHelpInfo()));
    connect(ui->delButton, SIGNAL(clicked()), this, SLOT(delItem()));
    connect(ui->clearButton, SIGNAL(clicked()), ui->listWidget, SLOT(clear()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(copy2Clipbrd(QListWidgetItem*)));
}

void Widget::copy2Clipbrd(QListWidgetItem *item){
    this->clipBrd->setText(item->text());
    return;
}

void Widget::delItem(){
    ui->listWidget->takeItem(ui->listWidget->currentRow());


    return;
}

void Widget::showHelpInfo(){
    int ret = QMessageBox::information(this, tr("Help of FancyClipboard"), \
                                       tr("<p>This is ...</p><p>Use:</p>"), \
                                       QMessageBox::Cancel);
}


void Widget::appendClip(){
    const QMimeData *mimeData = this->clipBrd->mimeData();


    QString text = clipBrd->text();
    for(int i=0;i!=ui->listWidget->count();++i){
        QListWidgetItem* curItem = ui->listWidget->item(i);
        if(curItem->text() == text){
            return;
        }
    }

    QListWidgetItem *item = new QListWidgetItem(text);
    if(ui->listWidget->count()%2==0){
        item->setBackgroundColor(QColor(240, 255, 255));
    }
    if(mimeData->hasImage()){
        item->setIcon(QIcon(":/listIcon/icon/img.png"));
    } else if(mimeData->hasHtml()){
        item->setIcon(QIcon(":/listIcon/icon/html.png"));
    } else{
        item->setIcon(QIcon(":/listIcon/icon/text.png"));
    }


    ui->listWidget->addItem(item);


    return;
}



Widget::~Widget()
{
    delete ui;
}
