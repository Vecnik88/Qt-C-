#include "mybutton.h"

MyButton::MyButton(const QString& _str, QWidget* wgt): QPushButton(wgt), str(_str){
    const size_t sizeIcon = 150;
    const size_t sizeButton = 100;
    setMouseTracking(true);
    setFixedSize(sizeButton, sizeButton);
    setIcon(QIcon(QPixmap(str)));
    setIconSize(QSize(sizeIcon, sizeIcon));
}

void MyButton::leaveEvent(QEvent* e)
{
    Q_EMIT notHovered();

    QWidget::leaveEvent(e);
}
void MyButton::enterEvent(QEvent* e)
{
    Q_EMIT hovered();

    QWidget::enterEvent(e);
}
