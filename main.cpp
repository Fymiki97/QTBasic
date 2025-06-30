#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    a.setWindowIcon(QIcon(".\\images\\window.ico"));
    w.show();
    return a.exec();
}
