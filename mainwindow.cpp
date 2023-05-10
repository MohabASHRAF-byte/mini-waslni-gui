
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent,QApplication* qapp)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mp= new Map();
    this->qapp = qapp;

    graph = mp->getGraph();
    this->navigateMenu=new Navigate(this,this->mp);
    this->editMenu=new Edit(this,this->mp);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete navigateMenu;
    delete editMenu;
    delete qapp;
    delete mp;
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


void MainWindow::on_exit_pushButton_clicked()
{
    qapp->quit();
}

