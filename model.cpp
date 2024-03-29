#include "model.h"

using namespace std;

Model::Model()
{

}

void Model::AddItem(Item* item)
{
    _items.push_back(item);
}

Item* Model::GetItem(int i)
{
    return *next(_items.begin(), i);
}

list<Item*> Model::GetAllItems()
{
    return _items;
}

void Model::RemoveItem(int i)
{
    list<Item*>::iterator it = next(_items.begin(), i);
    _items.remove(*it);
}

void Model::OnItemDeleted(int id)
{
    auto it = find_if(_items.begin(), _items.end(), [id](Item *i){return i->GetId()==id;});
    if(it != _items.end())
    {
        _items.erase(it);
    }
}

std::ostream& operator<<(std::ostream& os, const Model& model)
{
    for(auto item : model._items)
    {
        os << *item;
        if(item != model._items.back())
        {
            os << endl;
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Model& model)
{
    int id = 0;
    while(is.good())
    {
        Item *item = new Item(id++);
        is >> *item;
        model.AddItem(item);
    }
    return is;
}
