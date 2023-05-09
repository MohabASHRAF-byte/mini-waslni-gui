
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mp= new Map();
    graph = mp->getGraph();
    this->navigateMenu=new Navigate(this,this->mp);
    this->editMenu=new Edit(this,this->mp);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_navigate_pushButton_clicked()
{
    hide();
    this->navigateMenu->update();
    this->navigateMenu->show();
}


void MainWindow::on_edit_pushButton_clicked()
{
    hide();
    this->editMenu->show();
}

