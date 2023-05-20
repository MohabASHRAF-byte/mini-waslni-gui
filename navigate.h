#ifndef NAVIGATE_H
#define NAVIGATE_H

#include <QDialog>
#include <bits/stdc++.h>
#include "Node.h"
#include "map.h"
#include "algorithm.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "floyd.h"

#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class Navigate;
}

class Navigate : public QDialog
{
    Q_OBJECT

public:
    explicit Navigate(QWidget *parent = nullptr , Map *mp=nullptr);
    Map *mp;
    std::map<string,Node*>* graph;
    void update();
    ~Navigate();
    QVector<Point> path;

private slots:

    void on_back_pushButton_clicked();

    void on_Execute_pushButton_clicked();

    void on_Back_choose_pushButton_clicked();


    void on_run_pushButton_clicked();

private:
    Ui::Navigate *ui;
    Algorithm* algo;

    virtual void paintEvent(QPaintEvent* event);

};

#endif // NAVIGATE_H
