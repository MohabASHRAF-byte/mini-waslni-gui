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
    ui->add_city_groupBox->setVisible(false);
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_back_pushButton_clicked()
{
    hide();
    this->parentWidget()->show();
}

void Edit::reset(){
    ui->add_city_groupBox->setVisible(false);
    ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_3->clear();
    ui->operation_groupBox->setEnabled(true);
}
void Edit::on_add_city_save_pushButton_clicked()
{
    string cityName =ui->plainTextEdit->toPlainText().toStdString();
    int x_axis =ui->plainTextEdit_3->toPlainText().toInt();
    int y_axis =ui->plainTextEdit_2->toPlainText().toInt();

    auto &graph = mp->getGraphAddress(); //we get the address of the graph and edit on it
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
    for(auto &i:mp->getGraph()){
        qDebug()<<i<<"\n";
    }
    qDebug()<<"f this project\n";
    reset();

}


void Edit::on_add_city_radioButton_clicked()
{
    ui->operation_groupBox->setEnabled(false);
    ui->add_city_groupBox->setVisible(true);
}


void Edit::on_delete_city_radioButton_clicked()
{
    ui->delete_city_groupBox->setVisible(true);
    for(auto &i:mp->getGraph()){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->delete_edge_from_comboBox->addItem(city);
    }
}


void Edit::on_delete_edge_from_comboBox_currentTextChanged(const QString &arg1)
{
    ui->delete_city_to_comboBox->clear();
    auto node = mp->getGraph()[arg1.toStdString()];
    for(auto &i : node->edges){
        QString city = QString::fromStdString(i.first);  // Convert std::string to QString
        ui->delete_city_to_comboBox->addItem(city);
    }
}

