#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton {
    Q_OBJECT
private:
    QString str;

public:
    MyButton(const QString& _str, QWidget* wgt = Q_NULLPTR);

protected:
    virtual void enterEvent(QEvent* e);             // <---. событие входа в зону кнопки
    virtual void leaveEvent(QEvent* e);             // <---. событие выхода из зоны кнопки

public: Q_SIGNALS:
    void hovered();                                 // <---. сигнал мы в зоне
    void notHovered();                              // <---. сигнал мы вышли из зоны
};
#endif // MYBUTTON_H
