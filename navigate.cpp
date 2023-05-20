#include "navigate.h"
#include "ui_navigate.h"
#include <QMessageBox>
#include <QDebug>
Navigate::Navigate(QWidget *parent,Map * mp) :
    QDialog(parent),
    ui(new Ui::Navigate)
{
    ui->setupUi(this);
    this->mp=mp;
    QString algos[]={"BFS","DFS","Dijkstra","Floyd"};
    for(auto &algo :algos)
        ui->algorithm_comboBox->addItem(algo);

    image.load(":/images/Asset 5.png");
    imageActive.load(":/images/Asset 4.png");
}
void Navigate::update(){
    ui->from_comboBox->clear();
    ui->to_comboBox->clear();
//
    ui->algo_groupBox->setVisible(false);
//
    ui->Destination_groupBox->setEnabled(true);
//
    for(auto &i:this->mp->getGraph()){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->from_comboBox->addItem(city);
        ui->to_comboBox->addItem(city);
    }
}
Navigate::~Navigate()
{
    delete ui;
}


void Navigate::on_back_pushButton_clicked()
{
    hide();
    this->parentWidget()->show();
}



void Navigate::on_Execute_pushButton_clicked()
{
    if(ui->from_comboBox->currentIndex()==ui->to_comboBox->currentIndex()){
        QMessageBox::warning(this,"Destination","you choose the same source and destination");
        return;
    }
    ui->Destination_groupBox->setEnabled(false);
    ui->algo_groupBox->setVisible(true);
}


void Navigate::on_Back_choose_pushButton_clicked()
{
    ui->Destination_groupBox->setEnabled(!false);
    ui->algo_groupBox->setVisible(!true);
}





void Navigate::on_run_pushButton_clicked()
{
    auto convertedGraph = mp->getConvertedGraph();
    auto IdToName = mp->getIdToName();
    auto graph = mp->getGraph();

    //floyd is a special algorithm so we need to build it and run it first in order to
    //use it to its full capacity and get the result later and not compute it every time cuz it runs in
    //O(n^3)
       Floyd *floyd = new Floyd();
       floyd->build(convertedGraph);
       floyd->run(convertedGraph);


        string city1 =ui->from_comboBox->currentText().toStdString();
        string city2 =ui->to_comboBox->currentText().toStdString();
        Point p1, p2;
        p1.x = graph[city1]->point.x;
        p1.y = graph[city1]->point.y;

        p2.x = graph[city2]->point.x;
        p2.y = graph[city2]->point.y;

        switch (ui->algorithm_comboBox->currentIndex()) {
        case 0:
            algo = new BFS(p1, p2);
            algo->run(convertedGraph);
            path = algo->getPath(convertedGraph);
            break;
        case 1:
            algo = new DFS(p1, p2);
            algo->run(convertedGraph);
            path = algo->getPath(convertedGraph);
            break;
        case 2:
            algo = new Dijkstra(p1, p2);
            algo->run(convertedGraph);
            path = algo->getPath(convertedGraph);
            break;
        case 3:
            floyd->setPoints(p1, p2);
            path = floyd->getPath(convertedGraph);
            break;
        default:
            break;
        }
        qDebug()<<ui->algorithm_comboBox->currentText()<<"\n";
        if (path.front().x == oo and path.front().y == oo) {
            QMessageBox::warning(this,"Path","there is no path between chosen cities");
            ui->algo_groupBox->setVisible(false);
            ui->Destination_groupBox->setEnabled(true);
            return;
        }

        qDebug() << "path cost is : " << path.front().x << "\n";
        for (int i = 1; i < path.size(); ++i) {
            auto cityId = NodeConverter::axisToId(path[i].x, path[i].y, limitY);
            qDebug() << IdToName[cityId] << ' ';
            qDebug() << path[i].x << " " << path[i].y << "\n";
        }
        this->resize(width() - 1, height() - 1);
        this->resize(width() + 1, height() + 1);
}

void Navigate::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto graph = mp->getGraph();
    // Iterate through the nodes in the graph
    for (auto& iter : graph) {
        Node* node = iter.second;
        int x = node->point.x+240;
        int y = node->point.y;
        // Draw a circle for the node
        int radius = 15; // adjust the size of the circsle as needed
        painter.setPen(Qt::white);

        for (auto& edge : node->edges) {
            Node* otherNode = graph[edge.first];
            // Draw a line connecting the two nodes
            painter.drawLine(x, y, otherNode->point.x + 240, otherNode->point.y);
        }
    }

    for (auto& iter : graph) {
        Node* node = iter.second;
        int x = node->point.x+240;
        int y = node->point.y;
        int radius = 15; // adjust the size of the circsle as needed

        painter.drawPixmap(x - radius, y - radius, radius * 2, radius * 2, image);
        painter.drawText(QPointF(x + 15, y + 15), QString::fromStdString(iter.first));
    }

    for (int i = 1; i < path.size(); i++) {
        int x = path[i].x+240;
        int y = path[i].y;
        // Draw a circle for the node
        painter.setPen(Qt::green); // set the outline color of the circle

        // Draw a line connecting the two nodes
        if(i == path.size() - 1) continue;
        painter.drawLine(x, y, path[i + 1].x + 240, path[i + 1].y);
    }

    for (int i = 1; i < path.size(); i++) {
        int x = path[i].x+240;
        int y = path[i].y;
        // Draw a circle for the node
        int radius = 15; // adjust the size of the circsle as needed
        painter.drawPixmap(x - radius, y - radius, radius * 2, radius * 2, imageActive);
    }
}
