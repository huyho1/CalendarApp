#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H

#include <QDialog>
#include <QString>

namespace Ui {
class DaySchedule;
}

class DaySchedule : public QDialog
{
    Q_OBJECT

public:
    explicit DaySchedule(QWidget *parent = nullptr);
    ~DaySchedule();

private:
    Ui::DaySchedule *ui;
};

#endif // DAYSCHEDULE_H
