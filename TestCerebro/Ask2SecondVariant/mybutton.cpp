#include "mybutton.h"

MyButton::MyButton(const QString& _str, QWidget* wgt): QPushButton(wgt), str(_str){
    setMouseTracking(true);
    setFixedSize(100, 100);
    setIcon(QIcon(QPixmap(str)));
    setIconSize(QSize(150, 150));
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
