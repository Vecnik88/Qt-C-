#include <QtWidgets>
#include "MyServer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyServer server(1122);
    server.show();

    return a.exec();
}


