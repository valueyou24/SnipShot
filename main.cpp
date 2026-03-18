#include <QApplication>
#include "snipasteapp.h"


int main(int argc, char *argv[])
{
    //单例模式，对象只有一个,不能创建多个
    QApplication a(argc, argv);

    SnipasteApp sapp;


    return a.exec();
}
