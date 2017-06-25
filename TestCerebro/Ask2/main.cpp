// Created by Vecnik88 23.06.2017
/*                          Тестовое задание номер 2

Дано:
    Иконка для кнопок (в приложении к письму)

Условие:
    Использовать только один файл иконки из “Дано”.

Задание:
    Сделать окно с двумя кнопками, на которых отображается иконка.
    У первой кнопки, в нажатом состоянии должен меняться цвет фона на зеленый.
    У второй кнопки, при наведении должен меняться цвет иконки на зеленый.

*/

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // устанавливаем для всех кнопок картинку на заднем фоне по умолчанию
    app.setStyleSheet("QPushButton{background-image: url(D://TestGit/untitled121/fr.png);}");

    QWidget wgt;
    QPushButton* pcmd1 = new QPushButton;
    QPushButton* pcmd2 = new QPushButton;
    pcmd1->setFixedSize(50, 50);
    pcmd2->setFixedSize(50, 50);

    // Используем QSS для оформления кнопок
    pcmd1->setStyleSheet("QPushButton:pressed {background-color: green; border:none;}");
    pcmd2->setStyleSheet("QPushButton:hover {background-color: green; border:none;}");

    // Устанавливаем табличный слой
    QGridLayout* vbxButton = new QGridLayout;
    vbxButton->addWidget(pcmd1, 1, 1);
    vbxButton->addWidget(pcmd2, 1, 0);
    wgt.setLayout(vbxButton);

    wgt.setFixedSize(128, 128);
    wgt.show();

    return app.exec();
}
