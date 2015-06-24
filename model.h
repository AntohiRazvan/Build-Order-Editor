#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <algorithm>
#include "unittypes.h"
#include "item.h"

class Model
{
    std::list<Item*> _items;
public:
    Model();
    void AddItem(Item* item);
    Item* GetItem(int i);
    std::list<Item*> GetAllItems();
    void RemoveItem(int i);
};

#endif // MODEL_H
