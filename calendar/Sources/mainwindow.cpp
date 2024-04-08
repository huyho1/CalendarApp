#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "assignments.h"
#include "dayschedule.h"
#include "information.h"
#include "viewassignments.h"

QDate dateAccessed;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setVisible(false);

    connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::toggleCalendarVisibility);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog form;
    form.setModal(true);
    form.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    Dialog2 form;
    form.setModal(true);
    form.exec();
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    dateAccessed = date;
    DaySchedule output;
    output.setModal(true);
    output.exec();
}

void MainWindow::toggleCalendarVisibility(int state)
{
    // Toggle the visibility of the calendar based on the state of the checkBox
    ui->calendarWidget->setVisible(state != Qt::Checked);
    ui->tableWidget->setVisible(state == Qt::Checked);

    QTime startTime(0, 0);
    int rowNum = 1;

    std::vector<QTime> timeList;

    while (startTime <= QTime(23, 30)) {
        timeList.push_back(startTime);
        startTime = startTime.addSecs(30 * 60); // add 30 minutes
        ui->tableWidget->setRowCount(rowNum++);
        if (startTime == QTime(23,30)) {
            timeList.push_back(startTime);
            break;
        }
    }
    ui->tableWidget->setRowCount(rowNum);
    for (int row = 0; row < rowNum; ++row) {
        QTableWidgetItem *time = new QTableWidgetItem(timeList[row].toString("hh:mm AP"));
        ui->tableWidget->setVerticalHeaderItem(row, time);
    }

    QDate selectedDate = ui->calendarWidget->selectedDate();
    Qt::DayOfWeek firstDayOfWeek = ui->calendarWidget->firstDayOfWeek();
    int offset = firstDayOfWeek - selectedDate.dayOfWeek();

    std::vector<QDate> date;
    date.clear();
    for (int i = 7; i > 0; i--) {
        QDate firstDayOfWeekDate = selectedDate.addDays(offset-i);
        date.push_back(firstDayOfWeekDate);
        QString formattedDate = firstDayOfWeekDate.toString("M-d-yy");
        QString dayOfWeek = firstDayOfWeekDate.toString("dddd");
        QString headerText = QString("%1\n%2").arg(dayOfWeek).arg(formattedDate);
        ui->tableWidget->setHorizontalHeaderItem(7-i, new QTableWidgetItem(headerText));
    }

    ui->tableWidget->clearContents();
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < eventList.size(); j++) {
            auto addWeekView = [&] (int col, int numEvent) {
                int active = 0;
                for (int k = 0; k < timeList.size(); k++) {
                    if (timeList[k] <= eventList[numEvent].start && timeList[k].addSecs(30*60) > eventList[numEvent].start) {
                        active = 1;
                        if(ui->tableWidget->item(k, col) == nullptr || ui->tableWidget->item(k, col)->text().isEmpty()) {
                            ui->tableWidget->setItem(k, col, new QTableWidgetItem(eventList[numEvent].name));
                        }
                        else {
                            QString previous = ui->tableWidget->item(k, col)->text();
                            QString combine = QString("%1\n%2").arg(previous).arg(eventList[numEvent].name);
                            ui->tableWidget->setItem(k, col, new QTableWidgetItem(combine));
                        }
                    }
                    else if (active == 1 && timeList[k] < eventList[numEvent].end) {
                        if(ui->tableWidget->item(k, col) == nullptr || ui->tableWidget->item(k, col)->text().isEmpty()) {
                            ui->tableWidget->setItem(k, col, new QTableWidgetItem(eventList[numEvent].name));
                        }
                        else {
                            QString previous = ui->tableWidget->item(k, col)->text();
                            QString combine = QString("%1\n%2").arg(previous).arg(eventList[numEvent].name);
                            ui->tableWidget->setItem(k, col, new QTableWidgetItem(combine));
                        }
                    }
                    else {
                        active = 0;
                    }
                }
            };
            if (date[i] == eventList[j].firstDay || date[i] == eventList[j].lastDay) {
                addWeekView(i, j);
            }
            if (date[i] < eventList[j].lastDay && date[i] > eventList[j].firstDay) {
                if (date[i].dayOfWeek() == Qt::Monday && eventList[j].mon) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Tuesday && eventList[j].tues) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Wednesday && eventList[j].wed) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Thursday && eventList[j].thur) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Friday && eventList[j].fri) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Saturday && eventList[j].sat) {
                    addWeekView(i, j);
                }
                else if (date[i].dayOfWeek() == Qt::Sunday && eventList[j].sun) {
                    addWeekView(i, j);
                }
                else {
                    break;
                }
            }
        }
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    Dialog3 form;
    form.setModal(true);
    form.exec();
}

