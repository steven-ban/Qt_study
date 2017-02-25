#include<QApplication>
#include<QDebug>
#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // available codecs
    /*
    qDebug()<<"Available codecs: ";
    QList<QByteArray> availableCodecsList = QTextCodec::availableCodecs();
    for(auto codecName = availableCodecsList.constBegin(); \
        codecName != availableCodecsList.constEnd(); \
        ++codecName){
        qDebug()<<*codecName;
    }
    */

    qDebug()<<"current codec: "<<QTextCodec::codecForLocale()->name();

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

