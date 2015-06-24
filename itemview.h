#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <list>
#include "action.h"
#include "unittypes.h"

class ItemView : public QWidget
{
    Q_OBJECT
    QHBoxLayout *_layout;
    QComboBox *_actionSelector;
    std::list<QWidget*> _elements;

    void draw();
    void clear();
public:
    explicit ItemView(QWidget *parent = 0);

signals:

public slots:
    void OnActionSelected(int i);
};

#endif // ITEM_H
