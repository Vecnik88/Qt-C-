// Created by Vecnik88 25.06.2017

/*
Задание 1

Дано:

Есть набор ключей, связанных между собой отношениями parent-child.

Набор ключей:
1
2
3
4
10
11
111
20
31
32

Связи parent -> child:

1 -> 11
2 -> 20
3 -> 31
3 -> 32
11 -> 111

Задание:

    Реализовать класс модели, предоставляющей интерфейс для класса QTreeView по
    работе с деревом из данного набора ключей и их отношений.
    В качестве базового класса использовать QAbstractItemModel.
*/

#include "treemodel.h"

#include <QApplication>
#include <QFile>
#include <QTreeView>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QFile file("D://TestGit/untitled124/default.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel model(file.readAll());
    file.close();

    QTreeView pTreeView;
    pTreeView.setModel(&model);
    pTreeView.setFixedSize(300, 200);
    pTreeView.show();

    return app.exec();
}

