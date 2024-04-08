#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void updateButtonAvailability();

    void on_buttonBox_accepted();

private:
    Ui::Dialog2 *ui;
};

#endif // ASSIGNMENTS_H
