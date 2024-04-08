#ifndef EVENT_H
#define EVENT_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();
    void updateMinimumTime(const QTime &newTime);
    void updateMinimumDate(const QDate &newDate);
    void updateButtonAvailability();

private:
    Ui::Dialog *ui;
};

#endif // EVENT_H
