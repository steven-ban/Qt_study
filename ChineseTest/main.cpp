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

