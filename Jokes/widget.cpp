#include "widget.h"
#include "ui_widget.h"

#include<QByteArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    this->request = new QNetworkRequest;
    this->request->setUrl(QUrl("http://apis.baidu.com/showapi_open_bus/showapi_joke/joke_text?page=1"));
    this->request->setRawHeader(QByteArray("apikey"), QByteArray("8cbdc46ade09e505fd44c06a8d5eaae8"));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(jokeSelected()));
}

void Widget::pushButtonClicked(){
    this->manager->get(*request);
}

void Widget::jokeSelected(){

}

void Widget::replyFinished(QNetworkReply* mreply){
    QByteArray data = mreply->readAll();
    QJsonDocument jd = QJsonDocument::fromJson(data);
    //qDebug()<<data;
    if(jd.isObject()){
        QJsonObject jo = jd.object();
        //qDebug()<<jo.size();
        QJsonObject jo2 = jo.value(QString("showapi_res_body")).toObject();
        int jokesNum = jo2.value(QString("allNum")).toInt();    // jokes number
        int pageNum = jo2.value(QString("allPages")).toInt();   // page number
        qDebug()<<jokesNum<<pageNum;
        QJsonArray ja = jo2.value(QString("contentlist")).toArray();
        qDebug()<<ja.size();
        for(int i = 0; i <= ja.size(); ++i){
            QJsonValue itemV = ja.at(i);
            QJsonObject itemO = itemV.toObject();
            QString jokeText = itemO.value("title").toString();
            //ui->listWidget->insertItem(i, jokeText);
            QMap<QString, QString, QString> joke;
            joke["title"] = itemO.value("title").toString();
            joke["text"] = itemO.value("text").toString();
            joke["time"] = itemO.value("ct").toString();
            this->jokesList.append(joke);
            //qDebug()<<jokeText;
            //qDebug()<<ja.at(i).toString();
        }
    }


    for(i = 0 ; i<=this->jokesList.size(); ++i){
        ui->listWidget->addItem(jokesList.at(i).value("title"));
    }

}

Widget::~Widget()
{
    delete ui;
}