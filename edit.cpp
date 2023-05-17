#include "edit.h"
#include "qmessagebox.h"
#include "ui_edit.h"
#include "NodeConverter.h"
Edit::Edit(QWidget *parent,Map* mp) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    this->mp=mp;
    reset();

}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_back_pushButton_clicked()
{
    reset();
    hide();
    this->parentWidget()->show();
}


void Edit::reset(){
    ui->add_city_groupBox->setVisible(false);
    ui->delete_edge_groupBox->setVisible(false);
    ui->delete_city_groupBox_->setVisible(false);
    ui->add_edge_groupBox_->setVisible(false);

    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_3->clear();
    ui->operation_groupBox->setEnabled(true);

    ui->add_edge_to_comboBox_->clear();
    ui->delete_edge_from_comboBox->clear();
    ui->delete_edge_to_comboBox->clear();
    ui->add_edge_from_comboBox_->clear();


}


void Edit::on_add_city_radioButton_clicked()
{
    ui->operation_groupBox->setEnabled(false);
    ui->add_city_groupBox->setVisible(true);
}

bool containsOnlyNumbers(const QString& text)
{
    QRegularExpression regex("^[0-9]+$"); // Regular expression to match only numbers

    QRegularExpressionMatch match = regex.match(text);
    return match.hasMatch();
}

void Edit::on_add_city_save_pushButton_clicked()
{
//    try{

//    }
    QString city =  ui->plainTextEdit->toPlainText().trimmed();
    QString x_axis_str = ui->plainTextEdit_3->toPlainText().trimmed();
    QString y_axis_str = ui->plainTextEdit_2->toPlainText().trimmed();

    if(city.isEmpty() || x_axis_str.isEmpty()|| y_axis_str.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "You can't keep empty fields");
        return;
    }
    //
    if(!containsOnlyNumbers(x_axis_str)||!containsOnlyNumbers(y_axis_str))
    {
        QMessageBox::warning(this, "Warning", "Enter a valid coordinates");
        return;
    }
    //
    string cityName =city.toStdString();
    int x_axis =x_axis_str.toInt();
    int y_axis =y_axis_str.toInt();
    auto &graph = mp->getGraphAddress();
    //we get the address of the graph and edit on it

    if (graph[cityName]) {
        QMessageBox::warning(this,"exist","the name you entered already exists");
        reset();
        return;
    }
    Node *newNode = new Node(cityName, x_axis ,y_axis);
    graph[cityName] = newNode;

    int id = NodeConverter::axisToId(graph[cityName]->point.x, graph[cityName]->point.y, limitY);
    newNode->id = id;
    mp->getConvertedGraphAddress()[id];
    mp->getIdToNameAddress()[id]=cityName;
    reset();
}


void Edit::on_delete_edge_radioButton_clicked()
{
    ui->delete_edge_groupBox->setVisible(true);
    for(auto &i:mp->getGraph()){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->delete_edge_from_comboBox->addItem(city);
    }
}


void Edit::on_delete_edge_from_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "")return;
    ui->delete_edge_to_comboBox->clear();
    auto node = mp->getGraph()[arg1.toStdString()];
    for(auto &i : node->edges){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->delete_edge_to_comboBox->addItem(city);
    }
}


void Edit::on_delete_edge_save_pushButton_clicked()
{
    string fromCity = ui->delete_edge_from_comboBox->currentText().toStdString();
    string toCity = ui->delete_edge_to_comboBox->currentText().toStdString();

    auto &graph = mp->getGraphAddress(); //we get the address of the graph and edit on it
    auto &convertedGraph = mp->getConvertedGraphAddress();

    if (!graph[fromCity] || !graph[toCity]) {
        QMessageBox::warning(this,"exist","One of the cities does not exist!");
        reset();
        return;
    }

    int id1 = NodeConverter::axisToId(graph[fromCity]->point.x, graph[fromCity]->point.y, limitY);
    int id2 = NodeConverter::axisToId(graph[toCity]->point.x, graph[toCity]->point.y, limitY);

    if(graph[fromCity]->edges.find(toCity) != graph[fromCity]->edges.end()){
        graph[fromCity]->edges.erase(toCity);
        convertedGraph[id1].erase(id2);
    }
    else{
        QMessageBox::warning(this,"warning","There is no edge to the city you chose!");
        reset();
        return;
    }
    reset();
}


void Edit::on_delete_city_radioButton_clicked()
{
    ui->delete_city_comboBox->clear();

    ui->operation_groupBox->setEnabled(false);
    ui->delete_city_groupBox_->setVisible(true);

    for(auto& node : mp->getGraph()){

        QString city = QString::fromStdString(node.first);
        ui->delete_city_comboBox->addItem(city);
    }
}


void Edit::on_delete_city_save_pushButton_clicked()
{
    string city = ui->delete_city_comboBox->currentText().toStdString();

    auto &graph = mp->getGraphAddress(); //we get the address of the graph and edit on it
    auto &convertedGraph = mp->getConvertedGraphAddress();
    auto &IdToName = mp->getIdToNameAddress();
    //deleting all edges that go to our city
    for (auto &edge: graph[city]->edges) {
        graph[edge.first]->edges.erase(city);
    }
    for(auto &cityNode : graph){
        cityNode.second->edges.erase(city);
    }

    int id = NodeConverter::axisToId(graph[city]->point.x, graph[city]->point.y, limitY);
    mp->getGraphAddress().erase(city);

    for (auto &it: convertedGraph[id]) {
        convertedGraph[it].erase(id);
    }

    convertedGraph[id].clear();
    //convertedGraph.erase(id);
    IdToName.erase(id);

    reset();

}


void Edit::on_add_edge_radioButton_clicked()
{
    ui->operation_groupBox->setEnabled(false);
    ui->add_edge_groupBox_->setVisible(true);
    auto &graph = mp->getGraphAddress();
    for(auto &i:graph){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->add_edge_from_comboBox_->addItem(city);
    }
}


void Edit::on_add_edge_from_comboBox__currentTextChanged(const QString &arg1)
{
    if(arg1 == "")return;
    ui->add_edge_to_comboBox_->clear();
    //show all the edges that the arg1(from) can go to(existing edges will not appear)
    auto &node = mp->getGraphAddress();
    for(auto &i : node){
        //skip the edge if it already exists in the arg1 edges
        if(i.first == arg1.toStdString() || node[arg1.toStdString()]->edges.find(i.first) != node[arg1.toStdString()]->edges.end()) continue;
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->add_edge_to_comboBox_->addItem(city);
    }
}


void Edit::on_add_edge_save_pushButton__clicked()
{

    auto& graph = mp->getGraphAddress();
    auto& convertedGraph = mp->getConvertedGraphAddress();
    string city1, city2;
    city1= ui->add_edge_from_comboBox_->currentText().toStdString();
    city2= ui->add_edge_to_comboBox_->currentText().toStdString();

    bool isDirected = ui->isdirected_add_edge_checkBox->isChecked();

    int distance = (int) sqrt(pow((graph[city1]->point.x - graph[city2]->point.x), 2) +
                              pow((graph[city1]->point.y - graph[city2]->point.y), 2));
    graph[city1]->edges[city2] = distance;
    if(!isDirected)
        graph[city2]->edges[city1] = distance;

    //Converter
    int id1 = NodeConverter::axisToId(graph[city1]->point.x, graph[city1]->point.y, limitY);
    int id2 = NodeConverter::axisToId(graph[city2]->point.x, graph[city2]->point.y, limitY);
    //
    convertedGraph[id1].insert(id2); //
    ///./////
    if(!isDirected)
        convertedGraph[id2].insert(id1); //
    reset();
}
void Edit::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    auto graph = mp->getGraph();
    // Iterate through the nodes in the graph
    for (auto& iter : graph) {
        Node* node = iter.second;
        int x = node->point.x+200;
        int y = node->point.y;
        // Draw a circle for the node
        int radius = 10; // adjust the size of the circle as needed
        painter.setBrush(Qt::red); // set the fill color of the circle
        painter.setPen(Qt::black); // set the outline color of the circle
        painter.drawEllipse(x - radius , y - radius, radius * 2, radius * 2);

        // Draw the label for the node
        painter.drawText(QPointF(x + radius, y + radius), QString::fromStdString(iter.first));
        for (auto& edge : node->edges) {
            Node* otherNode = graph[edge.first];
            // Draw a line connecting the two nodes
            painter.drawLine(x, y, otherNode->point.x + 200, otherNode->point.y);
        }
    }
}


void Edit::on_adding_city_back_clicked()
{
    reset();
}


void Edit::on_deleting_edge_pushButton_clicked()
{
    reset();
}


void Edit::on_delete_city_pushButton_clicked()
{
    reset();
}


void Edit::on_pushButton_clicked()
{
    reset();
}

