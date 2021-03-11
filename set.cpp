#include "set.h"

Set::Set() : QVariant()
{
}

Set::Set(const QVariant &other) : QVariant(other)
{
}

Set::Set(int value) : QVariant(value)
{
}

Set::Set(const QList<QVariant> &elems) : QVariant(elems)
{
}

void Set::addNew(const Set &newValue)
{
    *this |= newValue;
}

bool Set::isSubset(const Set &other) const
{
    if ((*this | other) == *this) {
        return true;
    } else {
        return false;
    }
}

Set &Set::operator|=(int value)
{
    *this |= Set(value);
    return *this;
}

Set &Set::operator|=(const Set &other)
{
    QList<QVariant> thisList = this->toList();
    if (!thisList.contains(other)) {
        thisList.append(other);
        *this = QVariant(thisList);
    }
    return *this;
}

Set &Set::operator&=(int value)
{
    *this &= Set(value);
    return *this;
}

Set &Set::operator&=(const Set &other)
{
    QList<QVariant> thisList = this->toList();
    this->clear();
    if (!thisList.contains(other)) {
        *this = QVariant(other);
    }
    return *this;
}

const Set &operator|(const Set &s1, const Set &s2)
{
    return Set(s1) |= s2;
}

const Set &operator&(const Set &s1, const Set &s2)
{
    return Set(s1) &= s2;
}

