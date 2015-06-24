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

#include <QDebug>
void Item::OnViewChanged(vector<int> params)
{
    qDebug() << params[0] ;
}

ostream& operator<<(ostream& os, const Item& item)
{
    os << item._action;
    for(int i = 0; i < item._parameters.size(); i++)
    {
        os << " " << item._parameters[i];
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
            is >> temp;
            item._parameters.push_back(temp);
            break;
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
