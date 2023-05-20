
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QPixmap>
#include <QPalette>

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

    QPixmap backgroundImage(R"(C:\Users\Moamen Sherif\Desktop\drive-download-20230520T180835Z-001\Asset 11.png)"); // Replace with your image path
    // Create a palette with the desired background image
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(backgroundImage));
    // Set the palette on the widget
    this->setAutoFillBackground(true); // Ensure that the widget's background is filled
    this->setPalette(palette);
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

