#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();

private slots:

    void on_tableWidget_cellPressed(int row, int column);

private:
    Ui::Dialog3 *ui;
};

#endif // ASSIGNMENTVIEW_H
