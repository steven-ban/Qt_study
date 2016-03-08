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
        QJsonObject jj = jd.object().value(QString("weatherinfo")); // returns the pairs
        for(QJsonObject::iterator iter = jj.begin();
            iter != jj.end();
            ++iter){
            QString key = iter.key();
            QString defaultValue = QString("Not a string.");
            QJsonValueRef value = iter.value();
            QLabel* keyLabel = new QLabel(key);
            QLabel* valueLabel = new QLabel(value.toString());
            QHBoxLayout* valueLayout = new QHBoxLayout();
            valueLayout->deleteLater();
            valueLayout->addWidget(keyLabel);
            valueLayout->addWidget(valueLabel);
            ui->infoLayout->addLayout(valueLayout);
            this->show();
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
