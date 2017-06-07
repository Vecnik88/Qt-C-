#include <QApplication>
#include <myclient.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyClient myClient("localhost", 1122);
    myClient.show();

    return a.exec();
}




