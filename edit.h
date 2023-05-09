#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "map.h"
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

private slots:
    void on_back_pushButton_clicked();

    void on_add_city_save_pushButton_clicked();

    void on_add_city_radioButton_clicked();

    void on_delete_city_radioButton_clicked();

    void on_delete_edge_from_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::Edit *ui;
    Map* mp;
};

#endif // EDIT_H
