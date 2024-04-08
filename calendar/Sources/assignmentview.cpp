#include "assignmentview.h"
#include "information.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(assignmentList.size());
    for (int i = 0; i < assignmentList.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem (assignmentList[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem (assignmentList[i].dueDate.toString()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem (assignmentList[i].timeToComplete));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem (assignmentList[i].description));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem("Click to Delete"));
    }
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_tableWidget_cellPressed(int row, int column)
{
    if (column == 4) {
        ui->tableWidget->removeRow(row);
        assignmentList.erase(assignmentList.begin()+row);
    }
}

