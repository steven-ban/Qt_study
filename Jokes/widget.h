#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QMap>
#include<QList>

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

private slots:
    void replyFinished(QNetworkReply*);
    void pushButtonClicked();
    void jokeSelected(QListWidgetItem*);
};

#endif // WIDGET_H
