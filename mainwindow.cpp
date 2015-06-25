#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

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
    connect(iv, SIGNAL(ItemChanged(std::vector<int>)),
            i,  SLOT(OnItemChanged(std::vector<int>)));
    connect(iv, SIGNAL(ItemDeleted(int)),
            _model, SLOT(OnItemDeleted(int)));
    connect(this, SIGNAL(ClearView()),
            iv, SLOT(Delete()));
    counter++;
    _model->AddItem(i);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();

    if(fileName == "")
        return;

    ifstream file(fileName.toLatin1().data());
    _model = new Model();
    file >> *_model;
    emit ClearView();
    for(auto item : _model->GetAllItems())
    {
        vector<int> params;
        params.push_back(item->GetAction());
        for(auto param : item->GetParameters())
        {
            params.push_back(param);
        }
        _mainLayout->removeWidget(_newItemButton);
        ItemView *iv =  new ItemView(counter, params);
        _mainLayout->addWidget(iv);
        _mainLayout->addWidget(_newItemButton);
        connect(iv, SIGNAL(ItemChanged(std::vector<int>)),
                item,  SLOT(OnItemChanged(std::vector<int>)));
        connect(iv, SIGNAL(ItemDeleted(int)),
                _model, SLOT(OnItemDeleted(int)));
        connect(this, SIGNAL(ClearView()),
                iv, SLOT(Delete()));
    }
    file.close();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName();

    if(fileName == "")
        return;

    ofstream file(fileName.toLatin1().data());
    file << *_model;
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
