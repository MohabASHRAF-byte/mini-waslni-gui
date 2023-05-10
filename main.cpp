
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication* qapp = new QApplication(argc, argv);
    MainWindow w(nullptr,qapp);
    w.show();
    return qapp->exec();
}
