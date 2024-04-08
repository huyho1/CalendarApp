#include "assignments.h"
#include "QtWidgets/qpushbutton.h"
#include "ui_assignments.h"
#include "information.h"

std::vector<Assignment> assignmentList;

Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    // Connect lineEdit and lineEdit_2's textChanged signals to updateButtonAvailability slot
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dialog2::updateButtonAvailability);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &Dialog2::updateButtonAvailability);

    // Initially disable the acceptance button
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::updateButtonAvailability() {
    // Check if lineEdit, lineEdit_2, timeEdit, and dateEdit are not empty
    bool isLineEdit1Filled = !ui->lineEdit->text().isEmpty();
    bool isLineEdit2Filled = !ui->textEdit->toPlainText().isEmpty();
    bool isTimeEditFilled = !ui->doubleSpinBox->text().isEmpty();
    bool isDateEditFilled = !ui->dateTimeEdit->text().isEmpty();

    // Enable or disable the acceptance button based on field entries
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(isLineEdit1Filled && isLineEdit2Filled && isTimeEditFilled && isDateEditFilled);
}

void Dialog2::on_buttonBox_accepted()
{
    QString name = ui->lineEdit->text();
    QString info = ui->textEdit->toPlainText();
    QDateTime due = ui->dateTimeEdit->dateTime();
    QString etr = ui->doubleSpinBox->cleanText();

    assignment newAssignment;
    newAssignment.name = name;
    newAssignment.description = info;
    newAssignment.dueDate = due;
    newAssignment.timeToComplete = etr;

    assignmentList.push_back(newAssignment);
}

