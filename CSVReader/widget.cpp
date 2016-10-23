#include "widget.h"
#include "ui_widget.h"

#include<QFile>
#include<QStringList>
#include<QIODevice>
#include<QTextStream>
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->addPushButton, SIGNAL(clicked(bool)), this, SLOT(addCSVItem()));
    connect(ui->savePushButton, SIGNAL(clicked(bool)), this, SLOT(saveCSV()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(addCSVItem()));

    // read CSV file from default path
    QFile csvFile("test.csv");
    this->csvList.clear();

    if(csvFile.exists()){
        if(csvFile.open(QIODevice::ReadOnly)){
            QTextStream stream(&csvFile);
            while(!stream.atEnd()){
                this->csvList.push_back(stream.readLine());

            }
            csvFile.close();
        }
        ui->listWidget->addItems(this->csvList);
        ui->listWidget->update();
    }
    else {
        csvFile.open(QIODevice::WriteOnly);
        csvFile.write("test1");
        csvFile.close();
        QMessageBox::warning(this, tr("File not exsit!"),
                             tr("File test.csv not exsit! Please check you default path! We have created the file."));
    }

}

void Widget::addCSVItem(){
    if(ui->lineEdit->text().length() != 0){
        this->csvList.push_back(ui->lineEdit->text());
        ui->listWidget->insertItem(ui->listWidget->count(), ui->lineEdit->text());
        ui->lineEdit->clear();
        ui->listWidget->update();

    }
    else{
        int ret = QMessageBox::warning(this, tr("Information"),
                                       tr("Text Input now is empty.\n"));
    }
}

void Widget::saveCSV(){
    QFile csvFile("test.csv");
    if(csvFile.open(QIODevice::WriteOnly)){
        for(int i = 0; i < csvList.count();++i){
            csvFile.write(csvList.at(i).toLocal8Bit());
        }
    }

    csvFile.close();

}

Widget::~Widget()
{
    delete ui;
}
