//#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include "widget.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    Widget w;
    w.InitWidget();

    return a.exec();
}

