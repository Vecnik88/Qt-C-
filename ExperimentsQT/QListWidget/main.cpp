#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList lst;
    QListWidget lwg;
    QListWidgetItem* pitem = 0;

    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str, lst){
        pitem = new QListWidgetItem(str, &lwg);
    }
    lwg.resize(125,150);
    lwg.show();
    return a.exec();
}
