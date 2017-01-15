#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>

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

    QXmlStreamReader xml;
    QFile file;
    QString text;

private slots:
    bool selectFile();
    bool parseXML();
    void saveMDFile();
};

#endif // WIDGET_H
