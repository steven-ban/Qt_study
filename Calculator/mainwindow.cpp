#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString calcoperators("+-*/=");
const QString calcnumbers("0123456789.");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    connect(ui->numZeroButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numDotButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numOneButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numTwoButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numThreeButton_2, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numFourButton_2, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numFiveButton_2, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numSixButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numSevenButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numEightButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->numNineButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->plusButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->multiplyButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->divideButton, SIGNAL(clicked()), this, SLOT(updateNum()));
    connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(updateNum()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateNum(){
    QString text = ((QPushButton*)QObject::sender())->text();
    // operation
    if(calcnumbers.contains(text)){
        lastNum = lastNum * 10 + text.toInt();
    }
    if (calcoperators.contains(text)) {
        this->curNum = this->curNum + lastNum;
    }

    curStr.append(text);
    ui->displayLine->setText(this->curStr);
    ui->displayLine->update();
}
