#include "dayschedule.h"
#include "ui_dayschedule.h"
#include "information.h"

DaySchedule::DaySchedule(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DaySchedule)
{
    ui->setupUi(this);

    std::vector<Event> todayList;
    int rowNum = 0;
    for (unsigned i = 0; i < eventList.size(); i++) {
        if(dateAccessed == eventList[i].firstDay || dateAccessed == eventList[i].lastDay) {
        rowNum++;
        todayList.push_back(eventList[i]);
        }
        if (dateAccessed < eventList[i].lastDay && dateAccessed > eventList[i].firstDay) {
            if (dateAccessed.dayOfWeek() == Qt::Monday && eventList[i].mon) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Tuesday && eventList[i].tues) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Wednesday && eventList[i].wed) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Thursday && eventList[i].thur) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Friday && eventList[i].fri) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Saturday && eventList[i].sat) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else if (dateAccessed.dayOfWeek() == Qt::Sunday && eventList[i].sun) {
                rowNum++;
                todayList.push_back(eventList[i]);
            }
            else {
                break;
            }
        }
    }

    // Set the number of rows and columns in the table
    ui->tableWidget->setRowCount(rowNum);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Time Start"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Time End"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));

    // Populate the table with 0's
    for (int row = 0; row < rowNum; ++row) {
        QTableWidgetItem *name = new QTableWidgetItem(todayList[row].name);
        QTableWidgetItem *startTime = new QTableWidgetItem(todayList[row].start.toString("hh:mm AP"));
        QTableWidgetItem *endTime = new QTableWidgetItem(todayList[row].end.toString("hh:mm AP"));
        QTableWidgetItem *loc = new QTableWidgetItem(todayList[row].loco);
        ui->tableWidget->setItem(row, 0, name);
        ui->tableWidget->setItem(row, 1, startTime);
        ui->tableWidget->setItem(row, 2, endTime);
        ui->tableWidget->setItem(row, 3, loc);
    }
}

DaySchedule::~DaySchedule()
{
    delete ui;
}

