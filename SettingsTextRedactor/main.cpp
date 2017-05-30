// Created by Vecnik88
/* Pедактор в возможностью изменения оформления и сохранением текущих настроек */

#include <QApplication>
#include <MyProgramm.h>
#include <offoperationsystem.h>

int main(int argc, char *argv[])
{
    OffOperationSystem offOperationSystem(argc, argv);

    MyProgramm myprogramm;
    myprogramm.show();

    return offOperationSystem.exec();
}
