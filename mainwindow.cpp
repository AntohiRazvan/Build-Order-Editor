#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _centralWidget = new QWidget(this);
    _centralWidget->setMinimumSize(this->width(),100);
/*
    QComboBox *c1 = new QComboBox();
    c1->addItem("Hello");
 //   c1->resize(200, 50);
    QComboBox *c2 = new QComboBox();
    c2->addItem("Hello");
 //   c2->resize(200, 50);
    QComboBox *c3 = new QComboBox();
    c3->addItem("Hello");
  //  c3->resize(200, 50);

    QComboBox *c4 = new QComboBox();
    c4->addItem("Hello");
    c4->resize(200, 50);
    QComboBox *c5 = new QComboBox();
    c5->addItem("Hello");
    c5->resize(200, 50);
    QComboBox *c6 = new QComboBox();
    c6->addItem("Hello");
    c6->resize(200, 50);

    QHBoxLayout *l1 = new QHBoxLayout();

    l1->addWidget(c1);
    l1->addWidget(c2);
    l1->addWidget(c3);

    QHBoxLayout *l2 = new QHBoxLayout();
    l2->addWidget(c4);
    l2->addWidget(c5);
    l2->addWidget(c6);
*/
   // layout->addItem(l1);
  //  layout->addItem(l2);

    QVBoxLayout *layout = new QVBoxLayout();
    ItemView *iv = new ItemView();
    layout->addWidget(iv);
    _centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
