#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkReply>

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

    QNetworkAccessManager* qnam;
    QNetworkReply* reply;

private slots:
    void replyFinished(QNetworkReply*);
    void startRequest();
};

#endif // WIDGET_H