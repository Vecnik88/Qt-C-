//Created by Vecnik88
// эксперименты с QPushButton, QDialog и другие

#include <QApplication>
#include <StartDialog.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartDialog startDialog;
    startDialog.show();

    return app.exec();
}
