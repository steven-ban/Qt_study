#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    QClipboard *clipBrd;

public slots:
    void appendClip();
    // void changeClip();
    void showHelpInfo();
    void delItem();
    void copy2Clipbrd(QListWidgetItem*);
};

#endif // WIDGET_H
