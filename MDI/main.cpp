// Created by Vecnik88
// MDI приложение

#include <QApplication>
#include "mdiprogramm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MDIProgramm mdi;
    mdi.show();

    return a.exec();
}
