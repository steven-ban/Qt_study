#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "include/cppjieba/Jieba.hpp"

#include<vector>

#include<QStringList>
#include<QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->splitButton, SIGNAL(clicked()), this, SLOT(splitWords()));

}

void MainWindow::splitWords(){
    str1 = ui->plainTextEdit->toPlainText();
    if(str1.isEmpty()){
        return;
    }

    //init Jieba settings
    const char* const DICT_PATH = "./dict/jieba.dict.utf8";
    const char* const HMM_PATH = "./dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "./dict/user.dict.utf8";
    const char* const IDF_PATH = "./dict/idf.utf8";
    const char* const STOP_WORD_PATH = "./dict/stop_words.utf8";
    cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);

    std::vector<std::string> words;
    qDebug()<<"String: "<<str1<<"\n";
    jieba.Cut(str1.toStdString(), words, true);

    for(auto iter = words.begin(); iter != words.end(); ++iter){
        qDebug()<<"split"<<(*iter).c_str()<<"\n";
        ui->listWidget->addItem(QString::fromStdString(*iter));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
