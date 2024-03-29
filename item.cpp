#include "item.h"

using namespace std;

Item::Item(int id)
{
    _id = id;
    _action = None;
}

void Item::SetAction(Actions action)
{
    _action = action;
}

Actions Item::GetAction()
{
    return _action;
}

void Item::AddParameter(int param)
{
    _parameters.push_back(param);
}

vector<int> Item::GetParameters()
{
    return _parameters;
}

int Item::GetId()
{
    return _id;
}

void Item::OnItemChanged(vector<int> params)
{
    _parameters.clear();
    _action = (Actions)params[0];
    for(int i = 1; i < params.size(); i++)
    {
        _parameters.push_back(params[i]);
    }
}

ostream& operator<<(ostream& os, const Item& item)
{
    if(item._action != 0)
    {
        os << item._action;
        for(int i = 0; i < item._parameters.size(); i++)
        {
            os << " " << item._parameters[i];
        }
    }
    return os;
}

istream& operator>>(istream& is, Item& item)
{
    int temp;
    is >> temp;
    item._action = (Actions)temp;

    switch(temp)
    {
        case 1:
        case 2:
            is >> temp;
            item._parameters.push_back(temp);
            is >> temp;
            item._parameters.push_back(temp);
            break;
        default:
            break;
    }

    return is;
}

bool operator==(const Item& item1, const Item& item2)
{
    if(item1._action != item2._action)
        return false;
    if(item1._parameters.size() != item2._parameters.size())
        return false;
    for(int i = 0; i < item1._parameters.size(); i++)
    {
        if(item1._parameters[i] != item2._parameters[i])
            return false;
    }
    return true;
}
