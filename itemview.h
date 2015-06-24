#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <list>
#include <vector>
#include "action.h"
#include "unittypes.h"

class ItemView : public QWidget
{
    Q_OBJECT
    int _id;
    QHBoxLayout *_layout;
    QComboBox *_actionSelector;
    QPushButton *_deleteButton;
    std::vector<QWidget*> _elements;
    void draw();
    void clear();
public:
    explicit ItemView(int id, QWidget *parent = 0);

signals:
    void ItemChanged(std::vector<int>);

public slots:
    void OnActionSelected(int i);
    void OnItemChanged();
    void OnDeleteButtonPressed();
};

#endif // ITEM_H
