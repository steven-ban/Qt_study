#include "widget.h"
#include "ui_widget.h"

#include<QJsonDocument>
#include<QJsonObject>
#include<iterator>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startRequest()));

    qnam = new QNetworkAccessManager(this);
    connect(qnam, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

}

void Widget::startRequest(){
    QString url("http://www.weather.com.cn/data/cityinfo/101010100.html");
    this->reply = qnam->get(QNetworkRequest(url));

}

void Widget::replyFinished(QNetworkReply* mreply){
    QByteArray data = mreply->readAll();
    QJsonDocument jd = QJsonDocument::fromJson(data);
    qDebug()<<"Http reply data: "<<data<<"\n";
    if(jd.isObject()){
        // now only return "weatherinfo" and its key
        // not the pairs of info
        //
        QJsonObject jj = jd.object().value(QString("weatherinfo")).toObject(); // returns the pairs
        ui->tableWidget->setRowCount(jj.length());
        ui->tableWidget->setColumnCount(2);
        qDebug()<<jj.length();

        for(int i = 0; i <= jj.size(); ++i)
            {
            QString key = jj.keys().at(i);
            QString value = jj.value(key).toString();
            qDebug()<<key<<":\t"<<value<<"\n";
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(key));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(value));

        }

    }
    else{
        qDebug()<<"The reply cannot be converted to a JSON object.\n";

    }

}

Widget::~Widget()
{
    delete ui;
}
