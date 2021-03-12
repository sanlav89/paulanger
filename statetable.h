#ifndef STATETABLE_H
#define STATETABLE_H

#include <QList>
#include <QDebug>
#include <iostream>
#include <stdio.h>
#include "statetableitem.h"

using namespace std;

class StateTable : public QList<QList<StateTableItem>>
{
public:
    StateTable(const QStringList &states, const QString &title = QString());
    StateTable(const QString &fileName, const QString &title = QString());
    virtual void display();
    QString title() const;
    void setTitle(const QString &title);

    static QStringList contentFromFile(const QString &fileName);

private:
    QString m_title;

    void initFromStringList(const QStringList &states);
};

#endif // STATETABLE_H
