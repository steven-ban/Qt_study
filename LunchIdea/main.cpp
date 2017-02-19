#include "widget.h"
#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator appTrans;
    appTrans.load("zh-CN.qm");
    a.installTranslator(&appTrans);

    Widget w;
    w.show();

    return a.exec();
}
