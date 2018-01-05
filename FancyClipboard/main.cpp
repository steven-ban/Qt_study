#include "widget.h"
#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator tran;
    tran.load(":/translator/fc.qm");
    a.installTranslator(&tran);

    Widget w;
    w.show();




    return a.exec();
}
