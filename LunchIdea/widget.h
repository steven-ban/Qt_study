#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QStringList>

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
    QStringList lunchList;

private slots:
    void setAddTrue();
    void addLunchList();
    void decideLunch();
};

#endif // WIDGET_H
