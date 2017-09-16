#include "eightqueen.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow x;
    x.show();

    return a.exec();
}
