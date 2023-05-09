
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <bits/stdc++.h>
#include <QWidget>
#include "navigate.h"
#include "map.h"
#include "Node.h"
#include "edit.h"
using namespace std ;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_navigate_pushButton_clicked();

    void on_edit_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Navigate* navigateMenu;
    Edit* editMenu;
    Map *mp;
    std::map<string,Node*>graph;

};

#endif // MAINWINDOW_H
