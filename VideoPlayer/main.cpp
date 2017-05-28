#include <QApplication>
#include <videoplayer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VideoPlayer* vdp = new VideoPlayer;
    vdp->resize(500, 500);
    vdp->show();

    return a.exec();
}


