#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QMap>
#include<QList>
#include<QListWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QNetworkRequest *request;

    QList<QMap<QString, QString> > jokesList;
    QByteArray rawData;

private slots:
    void replyFinished(QNetworkReply*);
    void pushButtonClicked();
    void jokeSelected(QListWidgetItem*);
    void showRawData();
};

#endif // WIDGET_H
