#ifndef SET_H
#define SET_H

#include <QVariant>

class Set : public QVariant
{
public:
    Set();
    Set(const QVariant &other);
    Set(int value);
    Set(const QList<QVariant> &other);

    void addNew(const Set &newValue);
    bool isSubset(const Set &other) const;

    Set &operator|=(int value);
    Set &operator|=(const Set &other);
    Set &operator&=(int value);
    Set &operator&=(const Set &other);

    friend const Set &operator|(const Set &s1, const Set &s2);
    friend const Set &operator&(const Set &s1, const Set &s2);

private:

};

#endif // SET_H
