#ifndef PUSHBUTTONTEST_H
#define PUSHBUTTONTEST_H

#include "mybutton.h"

#include <QIcon>
#include <QSize>
#include <QImage>
#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsColorizeEffect>

class WidgetTest : public QWidget {
    Q_OBJECT
public:
    WidgetTest(const QString& _str = "", QWidget* wgt = Q_NULLPTR);

private:
    QString str;                            // <---. адрес нашей иконки
    MyButton* pcmd1;
    QHBoxLayout* hbxl;
    QPushButton* pcmd2;

    // ф-ция отвечающая за изменение нашей картинки
    QImage tint(QImage src, QColor color, qreal strength);

public slots:
    void slotImageGreen();                  // <---. устанавливает зеленую иконку на кнопку
    void slotStandartImage();               // <---. устанавливает стандартную иконку на кнопку
};
#endif // PUSHBUTTONTEST_H
