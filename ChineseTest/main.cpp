#include<QApplication>
#include<QDebug>
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // console test
    QString str1("你好Qt！");
    qDebug()<<str1<<"\n";
    qDebug()<<"一种"<<"\n";

    qDebug()<<"你好中国！\n";
    qDebug()<<"权利要求，说明书\n";

    // GUI test
    QWidget widTest;
    QVBoxLayout vLayout(&widTest);
    vLayout.addWidget(new QLabel(str1));
    vLayout.addWidget(new QLabel("一种……的方法"));
    widTest.show();

    return a.exec();
}

