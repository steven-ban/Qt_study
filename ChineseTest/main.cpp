#include<QApplication>
#include<QDebug>
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // console test
    QString str1("���Qt��");
    qDebug()<<str1<<"\n";
    qDebug()<<"һ��"<<"\n";

    qDebug()<<"����й���\n";
    qDebug()<<"Ȩ��Ҫ��˵����\n";

    // GUI test
    QWidget widTest;
    QVBoxLayout vLayout(&widTest);
    vLayout.addWidget(new QLabel(str1));
    vLayout.addWidget(new QLabel("һ�֡����ķ���"));
    widTest.show();

    return a.exec();
}

