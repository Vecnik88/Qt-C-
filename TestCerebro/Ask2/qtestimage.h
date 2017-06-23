#ifndef QTESTIMAGE_H
#define QTESTIMAGE_H

#include <QtWidgets>
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <QToolButton>

class QIcon;
class QPalette;
class QPushButton;
class QToolButton;
class QWidget;

class QTestImage : public QWidget{
    Q_OBJECT

private:
    QPixmap pix;
    QPushButton* pcmd1;
    QPushButton* pcmd2;

public:
    QTestImage(QWidget* wgt = 0);
    virtual ~QTestImage();

//public slots:
    //void slotButtonClickedGreen();

};
#endif // QTESTIMAGE_H
