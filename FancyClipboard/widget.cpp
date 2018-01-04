#include "widget.h"
#include "ui_widget.h"

#include<QClipboard>
#include<QApplication>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    clipBrd = QApplication::clipboard();

    ui->listWidget->addItem(clipBrd->text());

    connect(clipBrd, SIGNAL(dataChanged()), this, SLOT(appendClip()));



}

void Widget::appendClip(){
    QString text = clipBrd->text();
    ui->listWidget->insertItem(0, text);
    return;
}



Widget::~Widget()
{
    delete ui;
}
