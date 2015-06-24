#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QList>
#include <QFileDialog>
#include <QString>
#include <fstream>
#include "itemview.h"
#include "item.h"
#include "model.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Model *_model;
    QWidget *_centralWidget;
    QGridLayout *_mainLayout;
    QList<ItemView> _itemList;
    QPushButton *_newItemButton;


    static int counter;
    void AddItemView();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void ClearView();

public slots:
    void OnNewItemButton();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
