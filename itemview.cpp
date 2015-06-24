#include "itemview.h"


ItemView::ItemView(QWidget *parent) : QWidget(parent)
{
    _layout = new QHBoxLayout();
    _actionSelector = new QComboBox();
    _actionSelector->addItem(QString(Action::ToString(None)));
    _actionSelector->addItem(QString(Action::ToString(Build)));
    _actionSelector->addItem(QString(Action::ToString(Train)));
    _actionSelector->addItem(QString(Action::ToString(Attack)));
    connect(_actionSelector, SIGNAL(currentIndexChanged(int)),
            this, SLOT(OnActionSelected(int)));
    _layout->addWidget(_actionSelector);
    this->setLayout(_layout);
}

void ItemView::draw()
{
    for(auto elem : _elements)
    {
        _layout->addWidget(elem);
    }
}

void ItemView::OnActionSelected(int i)
{
    QWidget *elem;
    switch(i)
    {
        case 1:
            clear();
            elem = new QComboBox();
            for(auto building : UnitTypes::Buildings)
            {
                ((QComboBox*)elem)->addItem(QString(UnitTypes::ToString(building)));
            }
            _elements.push_back(elem);
            draw();
            break;
        case 2:
            clear();
            elem = new QComboBox();
            for(auto unit : UnitTypes::Units)
            {
                 ((QComboBox*)elem)->addItem(QString(UnitTypes::ToString(unit)));
            }
            _elements.push_back(elem);
            elem = new QSpinBox();
            _elements.push_back(elem);
            draw();
            break;
        default:
            clear();
            draw();
            break;

    }
}

void ItemView::clear()
{
   for(auto elem : _elements)
   {
       _layout->removeWidget(elem);
   }
   _elements.clear();
}
