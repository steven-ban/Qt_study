#include "widget.h"
#include "ui_widget.h"

#include<QFileDialog>
#include<QPushButton>
#include<QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->selectPathButton, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->addPathButton, SIGNAL(clicked()), this, SLOT(addPath()));
}

void Widget::selectFile(){
    this->dir = QFileDialog::getExistingDirectory(0, \
                                                    tr("Select file..."), \
                                                    ".");
    ui->lineEdit->setText(dir);
    int index = this->dir.indexOf("te", 0); // case insensitive
    qDebug()<<"index of steven: "<<index;
    if(index != -1){

        this->dir.insert(index, "<font color=#ff0000>");
        index += 20;
        this->dir.insert(index + 2, "</font>");

    }
    qDebug()<<"dir: "<<this->dir;

}

void Widget::addPath(){

    ui->listWidget->addItem(this->dir);
}

Widget::~Widget()
{
    delete ui;
}
