#include "itemview.h"

using namespace std;

ItemView::ItemView(int id, QWidget *parent) : QWidget(parent)
{
    _id = id;
    _layout = new QHBoxLayout();
    _actionSelector = new QComboBox();
    _actionSelector->addItem(QString(Action::ToString(None)));
    _actionSelector->addItem(QString(Action::ToString(Build)));
    _actionSelector->addItem(QString(Action::ToString(Train)));
    _actionSelector->addItem(QString(Action::ToString(Attack)));
    connect(_actionSelector, SIGNAL(currentIndexChanged(int)),
            this, SLOT(OnActionSelected(int)));
    _layout->addWidget(_actionSelector);
    _deleteButton = new QPushButton();
    _deleteButton->setText("Remove");
    connect(_deleteButton, SIGNAL(pressed()),
            this, SLOT(OnDeleteButtonPressed()));
    _layout->addWidget(_deleteButton);
    this->setLayout(_layout);
    connect(_actionSelector, SIGNAL(currentIndexChanged(int)),
            this, SLOT(OnItemChanged()));
}

void ItemView::draw()
{
    _layout->removeWidget(_deleteButton);
    for(auto elem : _elements)
    {
        _layout->addWidget(elem);
    }
    _layout->addWidget(_deleteButton);
}

void ItemView::clear()
{
    vector<QWidget*>::iterator i = _elements.begin();
    while (i != _elements.end())
    {
        auto elem = _elements.front();
        _elements.erase(i);
        delete(elem);
        i=_elements.begin();
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
            connect(elem, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(OnItemChanged()));
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
            connect(elem, SIGNAL(currentIndexChanged(int)),
                    this, SLOT(OnItemChanged()));
            elem = new QSpinBox();
            _elements.push_back(elem);
            connect(elem, SIGNAL(valueChanged(int)),
                    this, SLOT(OnItemChanged()));
            draw();
            break;
        default:
            clear();
            draw();
            break;
    }
}

void ItemView::OnDeleteButtonPressed()
{
    emit ItemDeleted(_id);
    delete this;
}


void ItemView::OnItemChanged()
{
    vector<int> ret;

    ret.push_back(Action::ToAction(_actionSelector->currentText().toStdString().c_str()));
    switch(Action::ToAction(_actionSelector->currentText().toStdString().c_str()))
    {
        case 1:
        ret.push_back(UnitTypes::ToUnitType(_actionSelector->currentText().toStdString().c_str()));
            break;
        case 2:
            ret.push_back(UnitTypes::ToUnitType(_actionSelector->currentText().toStdString().c_str()));
            ret.push_back(((QSpinBox*)_elements[1])->value());
            break;
    }
    emit ItemChanged(ret);
}
