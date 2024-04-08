#ifndef INFORMATION_H
#define INFORMATION_H

#include "QtCore/qdatetime.h"
#include <vector>
#include <QDialog>

struct event {
    QString name;
    QString loco;
    QTime start;
    QTime end;
    QDate firstDay;
    QDate lastDay;
    bool mon;
    bool tues;
    bool wed;
    bool thur;
    bool fri;
    bool sat;
    bool sun;
};

struct assignment {
    QString name;
    QString description;
    QDateTime dueDate;
    QString timeToComplete;
};

typedef struct event Event;
typedef struct assignment Assignment;

extern std::vector<Event> eventList;
extern std::vector<Assignment> assignmentList;
extern QDate dateAccessed;

#endif // INFORMATION_H
