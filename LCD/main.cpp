// электронный индикатор
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    QLCDNumber* plcd = new QLCDNumber;
    QSpinBox* pspb = new QSpinBox;

    plcd->setSegmentStyle(QLCDNumber::Filled);
    plcd->setMode(QLCDNumber::Hex);

    QObject::connect(pspb, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));

    QVBoxLayout* vbl = new QVBoxLayout;
    vbl->addWidget(plcd);
    vbl->addWidget(pspb);

    wgt.setLayout(vbl);
    wgt.resize(200,200);
    wgt.show();

    return a.exec();
}
