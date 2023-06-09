#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "map.h"


#include <QPainter>
#include <QPaintEvent>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include "Algorithm.h"

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr,Map* mp=nullptr);
    void reset();
    ~Edit();
    QPixmap image;

private slots:
    void on_back_pushButton_clicked();
    //AddCity
    void on_add_city_save_pushButton_clicked();

    void on_add_city_radioButton_clicked();

    //DeleteEdge
    void on_delete_edge_radioButton_clicked();

    void on_delete_edge_from_comboBox_currentTextChanged(const QString &arg1);

    void on_delete_edge_save_pushButton_clicked();


    //DeleteCity
    void on_delete_city_radioButton_clicked();

    void on_delete_city_save_pushButton_clicked();

    //AddEdge
    void on_add_edge_radioButton_clicked();

    void on_add_edge_from_comboBox__currentTextChanged(const QString &arg1);

    void on_add_edge_save_pushButton__clicked();

    void on_adding_city_back_clicked();

    void on_deleting_edge_pushButton_clicked();

    void on_delete_city_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Edit *ui;
    Map* mp;
    virtual void paintEvent(QPaintEvent* event);

};

#endif // EDIT_H
