#ifndef ITEM_H
#define ITEM_H

#include "action.h"
#include <vector>
#include <iostream>
#include <QObject>
#include <vector>

class Item : public QObject
{
    Q_OBJECT
    int _id;
    Actions _action;
    std::vector<int> _parameters;
public:
    Item(int id);
    void SetAction(Actions action);
    Actions GetAction();
    int GetId();

    void AddParameter(int param);
    std::vector<int> GetParameters();

    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);
    friend bool operator==(const Item& item1, const Item& item2);

public slots:
        void OnItemChanged(std::vector<int>);
};

#endif // ITEM_H
