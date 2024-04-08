#include "event.h"
#include "QtWidgets/qpushbutton.h"
#include "ui_event.h"
#include "information.h"

std::vector<Event> eventList;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // Connect signals and slots to update minimum time and date
    connect(ui->timeEdit, &QTimeEdit::timeChanged, this, &Dialog::updateMinimumTime);
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &Dialog::updateMinimumDate);

    // Connect lineEdit and lineEdit_2's textChanged signals to updateButtonAvailability slot
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dialog::updateButtonAvailability);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &Dialog::updateButtonAvailability);

    // Initially disable the acceptance button
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    QString name = ui->lineEdit->text();
    QString location = ui->lineEdit_2->text();
    QTime time1 = ui->timeEdit->time();
    QTime time2 = ui->timeEdit_2->time();
    QDate beginDay = ui->dateEdit->date();
    QDate endDay = ui->dateEdit_2->date();
    bool day1 = ui->checkBox->isChecked();
    bool day2 = ui->checkBox_2->isChecked();
    bool day3 = ui->checkBox_3->isChecked();
    bool day4 = ui->checkBox_4->isChecked();
    bool day5 = ui->checkBox_5->isChecked();
    bool day6 = ui->checkBox_6->isChecked();
    bool day7 = ui->checkBox_7->isChecked();

    Event newEvent;
    newEvent.name = name;
    newEvent.loco = location;
    newEvent.start = time1;
    newEvent.end = time2;
    newEvent.firstDay = beginDay;
    newEvent.lastDay = endDay;
    newEvent.mon = day1;
    newEvent.tues = day2;
    newEvent.wed = day3;
    newEvent.thur = day4;
    newEvent.fri = day5;
    newEvent.sat = day6;
    newEvent.sun = day7;

    eventList.push_back(newEvent);
}

void Dialog::updateMinimumTime(const QTime &newTime)
{
    ui->timeEdit_2->setMinimumTime(newTime);
}

void Dialog::updateMinimumDate(const QDate &newDate)
{
    ui->dateEdit_2->setMinimumDate(newDate);
}

void Dialog::updateButtonAvailability()
{
    // Check if lineEdit, lineEdit_2, timeEdit, and dateEdit are not empty
    bool isLineEdit1Filled = !ui->lineEdit->text().isEmpty();
    bool isLineEdit2Filled = !ui->lineEdit_2->text().isEmpty();
    bool isTimeEditFilled = !ui->timeEdit->text().isEmpty();
    bool isDateEditFilled = !ui->dateEdit->text().isEmpty();

    // Enable or disable the acceptance button based on field entries
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isLineEdit1Filled && isLineEdit2Filled && isTimeEditFilled && isDateEditFilled);
}
