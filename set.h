#ifndef SET_H
#define SET_H

#include <QVariant>
#include <QDebug>
#include <iostream>
#include <stdio.h>

class Set : public QList<int>
{
public:
    Set();
    Set(const QList<int> &other);
    Set(int value);

    void addNew(const Set &newValue);
    bool isSubsetOfThis(const Set &other) const;

    Set &operator|=(int value);
    Set &operator|=(const Set &other);
    Set &operator&=(int value);
    Set &operator&=(const Set &other);

    friend Set operator|(const Set &s1, const Set &s2);
    friend Set operator&(const Set &s1, const Set &s2);

    void display() const;
    QString toString() const;

private:

};

#endif // SET_H
