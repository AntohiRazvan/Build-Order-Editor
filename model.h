#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <algorithm>
#include <QObject>
#include "unittypes.h"
#include "item.h"

class Model : public QObject
{
    Q_OBJECT
    std::list<Item*> _items;
public:
    Model();
    void AddItem(Item* item);
    Item* GetItem(int i);
    std::list<Item*> GetAllItems();
    void RemoveItem(int i);

public slots:
    void OnItemDeleted(int id);
};

#endif // MODEL_H
