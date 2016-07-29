#include "widget.h"
#include "ui_widget.h"

#include<QFile>
#include<QXmlStreamWriter>
#include<QDateTime>
#include<QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile xmlFile("settings.xml");
    if(!xmlFile.exists()){
        xmlFile.open(QIODevice::WriteOnly);
        QXmlStreamWriter stream(&xmlFile);
        stream.setAutoFormatting(true);
        stream.setCodec("utf-8");
        stream.writeStartDocument();
        stream.writeStartElement("settings");
        stream.writeAttribute("version", "1.0");
        stream.writeAttribute("Author", "Steven Ban");
        stream.writeAttribute("Date", QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd"));

        stream.writeStartElement("Claims Sensitive Words");
        stream.writeTextElement("sensitive words", "´óÔ¼");
        stream.writeTextElement("sensitive words", "on");
        stream.writeEndElement();

        stream.writeStartElement("Description Sensitve Words");
        stream.writeEndElement();

        stream.writeEndDocument();

        xmlFile.close();
    }

    xmlFile.open(QIODevice::ReadOnly);

    this->ui->textBrowser->setText(xmlFile.readAll());
    xmlFile.seek(0);    // move file current index to top of file
    this->ui->treeWidget->setColumnCount(2);
    QList<QTreeWidgetItem*> topItems;
    QXmlStreamReader xmlRead(&xmlFile);
    // crashed down, don't know why
    while(!xmlFile.atEnd()){
        xmlRead.readNext();
        QTreeWidgetItem curTreeWidgetItem;
        curTreeWidgetItem.setText(1, xmlRead.name().toString());
        qDebug()<<xmlRead.name().toString();
        topItems.append(&curTreeWidgetItem);
    }
    if(xmlRead.hasError()){
        qDebug()<<"Crashed!";
    }

    this->ui->treeWidget->insertTopLevelItems(2, topItems);

    xmlFile.close();







}

Widget::~Widget()
{
    delete ui;
}
