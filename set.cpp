#include "set.h"

Set::Set() : QList<int>()
{
}

Set::Set(const QList<int> &other) : QList<int>(other)
{
}

Set::Set(int value) : QList<int>()
{
    this->append(value);
}

void Set::addNew(const Set &newValue)
{
    *this |= newValue;
}

bool Set::isSubsetOfThis(const Set &other) const
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
    if (other.size() != 0) {
        for (int i = 0; i < other.size(); i++) {
            if (!this->contains(other.at(i))) {
                this->append(other.at(i));
            }
        }
        qSort(*this);
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
    for (int value : *this) {
        if (!other.contains(value)) {
            removeOne(value);
        }
    }
    return *this;
}

void Set::display() const
{
    printf("{");
    for (int i = 0; i < this->size(); i++) {
        printf("%d", this->at(i));
        if (i < this->size() - 1) {
            printf(",");
        }
    }
    printf("}");
}

QString Set::toString() const
{
    QString result;
    result.append(QString::asprintf("{"));
    for (int i = 0; i < this->size(); i++) {
        result.append(QString::asprintf("%d", this->at(i)));
        if (i < this->size() - 1) {
            result.append(QString::asprintf(","));
        }
    }
    result.append(QString::asprintf("}"));
    return result;
}

Set operator|(const Set &s1, const Set &s2)
{
    Set result = s1;
    result |= s2;
    return result;
}

Set operator&(const Set &s1, const Set &s2)
{
    Set result = s1;
    result &= s2;
    return result;
}

