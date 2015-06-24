#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::counter = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(400, 600);

    _model = new Model();

    _centralWidget = new QWidget();
    _mainLayout = new QGridLayout(_centralWidget);
    ui->scrollArea->setWidget(_centralWidget);
    ui->scrollArea->setWidgetResizable(true);
    _mainLayout->setAlignment(Qt::AlignTop);
    _newItemButton = new QPushButton();
    _newItemButton->setText("New");
    _mainLayout->addWidget(_newItemButton);
    connect(_newItemButton, SIGNAL(pressed()), this, SLOT(OnNewItemButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnNewItemButton()
{
    Item *i = new Item(counter);
    _mainLayout->removeWidget(_newItemButton);
    ItemView *iv =  new ItemView(counter);
    _mainLayout->addWidget(iv);
    _mainLayout->addWidget(_newItemButton);
    connect(iv, SIGNAL(ItemChanged(std::vector<int>)), \
            i,  SLOT(OnViewChanged(std::vector<int>)));
    counter++;
}
