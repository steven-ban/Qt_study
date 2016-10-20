#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Jokes");
    Widget w;
    w.setWindowTitle("Jokes");
    w.show();

    return a.exec();
}
