#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>


class TreeItem{
public:
    explicit TreeItem(const QList<QVariant>& data, TreeItem* parentItem = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);                  // <---. добавить ребенка

    TreeItem *child(int row);                           // <---. ссылка на ребенка по позиции
    int childCount() const;                             // <---. кол-во детей
    int columnCount() const;
    QVariant data(int column) const;                    // <---. данные
    int row() const;
    TreeItem *parentItem();                             // <---. возвращает ссылка на родителя

private:
    QList<TreeItem*> m_childItems;                      // <---. список детей элемента
    QList<QVariant> m_itemData;
    TreeItem *m_parentItem;                             // <---. родитель
};

#endif // TREEITEM_H
