#ifndef STATETABLE_H
#define STATETABLE_H

#include <QList>
#include <QDebug>
#include <iostream>
#include <stdio.h>

using namespace std;

class StateTable : public QList<QList<int>>
{
public:
    StateTable();
    StateTable(const QStringList &states, const QString &title = QString());
    virtual void display();

    QString title() const;
    void setTitle(const QString &title);

private:
    QString m_title;
};

#endif // STATETABLE_H
