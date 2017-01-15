#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle((tr("Mindmap Parser")));
    connect(ui->selectButton, SIGNAL(clicked()),
            this, SLOT(selectFile()));
    connect(ui->parseButton, SIGNAL(clicked()),
            this, SLOT(parseXML()));
    connect(ui->saveButton, SIGNAL(clicked()),
            this, SLOT(saveMDFile()));
}

void Widget::saveMDFile(){
    QString fn = QFileDialog::getSaveFileName(
                this, tr("Save a .md file"),
                ".",
                tr("Markdown files(*.md)"));
    QFile mdFile;
    mdFile.setFileName(fn);
    if(!mdFile.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, tr("File cannot write!"),
                              tr("This file cannot be written! Please check your file!")
                              );
        return;
    }
    mdFile.write(this->text.toUtf8());
    mdFile.close();
}

bool Widget::selectFile(){
    QString filename = QFileDialog::getOpenFileName(this,
                   tr("Open a .mm file"),
                   ".",
                   tr("FreeMind files (*.mm)"));
    this->file.setFileName(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, tr("File cannot read!"),
                              tr("This file cannot be read! Please check your file!")
                              );
        return false;
    }
    ui->lineEdit->setText(filename);

    xml.setDevice(&file);

    return true;
}

bool Widget::parseXML(){
    int titleLevel = 0;
    while(!xml.atEnd()){
        if(xml.isStartElement()){
            titleLevel += 1;
        }
        if(xml.isEndElement()){
            titleLevel -= 1;
        }
//        if(titleLevel > 6){
//            titleLevel = 6;
//        }
        xml.readNext();
        if(!xml.attributes().value("TEXT").isEmpty()){


            if(titleLevel > 6){
                this->text.append(" - ");
            }
            else {
                this->text.append(QString("#").repeated(titleLevel));

            }
            this->text.append(xml.attributes().value("TEXT"));
            this->text.append("\n");
        }
    }

    ui->textEdit->setText(text);

    return true;
}

Widget::~Widget()
{
    delete ui;
}
