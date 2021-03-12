#ifndef MULTISET_H
#define MULTISET_H

#include "set.h"

class MultiSet : public QList<Set>
{
public:
    MultiSet();
    MultiSet(const QList<Set> &other);

    void addSet(const Set &newSet);
    void addMultiSet(const MultiSet &newMultiSet);
    void minimize();

    MultiSet &operator|=(int value);
    MultiSet &operator|=(const Set &other);
    MultiSet &operator&=(int value);
    MultiSet &operator&=(const Set &other);

    void display();
    QString toString() const;

};

#endif // MULTISET_H
