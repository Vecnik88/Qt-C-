//Created by Vecnik88
// Эксперименты с QMenu and QMenuBar

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMenuBar* mnuBar = new QMenuBar;
    QWidget wgt;
    QMenu* pmnu = new QMenu("&Menu");
    pmnu->setTearOffEnabled(true);              // <---. отрывное меню
    pmnu->addAction("&About Qt", &app, SLOT(aboutQt()), Qt::CTRL + Qt::Key_Q);
    pmnu->addSeparator();
    QAction* pCheckableAction = pmnu->addAction("&ChekableItem");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);

    QMenu* pmnSubMenu = new QMenu("&Submenu", pmnu);
    pmnu->addMenu(pmnSubMenu);
    pmnSubMenu->addAction("&Test");

    QAction* pDisableAction = pmnu->addAction("&DisabledItem");
    pDisableAction->setEnabled(false);

    pmnu->addSeparator();
    pmnu->addAction("&Exit", &app, SLOT(quit()));

    mnuBar->addMenu(pmnu);
    //mnuBar.show();
    QVBoxLayout* vbx = new QVBoxLayout;
    vbx->addWidget(mnuBar);
    //vbx->addWidget(pmnu);
    wgt.setLayout(vbx);
    wgt.show();

    return app.exec();
}





