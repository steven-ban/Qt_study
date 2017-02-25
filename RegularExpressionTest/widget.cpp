#include "widget.h"
#include "ui_widget.h"

#include<QMessageBox>
#include<QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->parseButton, &QPushButton::clicked, this, &Widget::parseRegExp);

}

void Widget::parseRegExp(){
    QString text = ui->plainTextEdit->toPlainText();
    if(text.isEmpty()){
        QMessageBox::critical(0, tr("No text found!"), \
                              tr("There is no text in editor. \nPlease input text!"));
        return ;
    }
    QString pattern = ui->lineEdit->text();

    QRegularExpression re(pattern);
    if(re.isValid()){
        qDebug()<<"re is "<<re.pattern();
        QRegularExpressionMatchIterator i = re.globalMatch(text);
        while(i.hasNext()){
            QRegularExpressionMatch match = i.next();
            qDebug()<<"matched: "<<match.captured(1);
            ui->listWidget->addItem(match.captured(1));
        }

    }
    else {
        QMessageBox::critical(0, tr("Regular expression invalid!"), \
                              tr("Invalid regular expression! \nPlease input right re."));
    }


}

Widget::~Widget()
{
    delete ui;
}
