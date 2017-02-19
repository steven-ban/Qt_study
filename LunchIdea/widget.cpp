#include "widget.h"
#include "ui_widget.h"

#include<QSettings>
#include<QStringList>
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // ui->addButton->setEnabled(false);

    QSettings settings("SIPO", "Steven");
    this->lunchList = settings.value("LunchList", tr("He Fan")).toStringList();

    ui->listWidget->addItems(this->lunchList);

    connect(ui->lineEdit, SIGNAL(textChanged()), this, SLOT(setAddTrue()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addLunchList()));
    connect(ui->decideButton, SIGNAL(clicked()), this, SLOT(decideLunch()));
}

void Widget::decideLunch(){
    int listLength = this->lunchList.length();
    int randomIndex = qrand() % listLength;
    QString lunch = this->lunchList.at(randomIndex);
    int msg = QMessageBox::information(0, tr("Today's decision"), \
                                       lunch);
}

void Widget::setAddTrue(){
    if(!ui->lineEdit->text().isEmpty()){
        ui->addButton->setEnabled(true);
        ui->addButton->update();
    }

}

void Widget::addLunchList(){
    QString lunch = ui->lineEdit->text();
    if (!this->lunchList.contains(lunch)){
        this->lunchList.append(lunch);
        ui->listWidget->addItem(lunch);
        ui->listWidget->update();
    }

}

Widget::~Widget()
{
    QSettings settings("SIPO", "Steven");
    settings.setValue("LunchList", this->lunchList);

    delete ui;
}
