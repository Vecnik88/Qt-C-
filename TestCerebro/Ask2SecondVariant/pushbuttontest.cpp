#include "pushbuttontest.h"

WidgetTest::WidgetTest(const QString& _str, QWidget* wgt):QWidget(wgt), str(_str){
    pcmd1 = new MyButton(str);
    pcmd2 = new MyButton(str);
    pcmd2->setStyleSheet("QPushButton:pressed {background-color: green; border:none;}");

    // накладываем кнопки на виджет в виде горизонтального слоя
    hbxl = new QHBoxLayout;
    hbxl->addWidget(pcmd1);
    hbxl->addWidget(pcmd2);
    setLayout(hbxl);

    // когда мышка над кнопкой
    connect(pcmd1, SIGNAL(hovered()), this, SLOT(slotImageGreen()));
    // когда мышка ушла из зоны кнопки
    connect(pcmd1, SIGNAL(notHovered()), this, SLOT(slotStandartImage()));
}

void WidgetTest::slotStandartImage(){     // <---. устанавливает стандартную картинку
    pcmd1->setIcon(QIcon(QPixmap(str)));
}

void WidgetTest::slotImageGreen(){        // <---. устанавливает обработанную картинку
    pcmd1->setIcon(QIcon(QPixmap::fromImage(tint(QImage(str), QColor(0,255,0),1.0))));
}

// отвечает за изменения цвета у картинки
QImage WidgetTest::tint(QImage src, QColor color, qreal strength){
    if(src.isNull())
        return QImage();

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    QGraphicsColorizeEffect effect;
    effect.setColor(color);
    effect.setStrength(strength);
    item.setGraphicsEffect(&effect);
    scene.addItem(&item);
    QImage res(src);
    QPainter ptr(&res);
    scene.render(&ptr, QRectF(), src.rect());

    return res;
}
