#include "multiset.h"

MultiSet::MultiSet() : QList<Set>()
{
}

MultiSet::MultiSet(const QList<Set> &other) : QList<Set>(other)
{
}

void MultiSet::addSet(const Set &newSet)
{
    this->append(newSet);
}

void MultiSet::addMultiSet(const MultiSet &newMultiSet)
{
    this->append(newMultiSet);
}

void MultiSet::minimize()
{
    QList<int> indexes;
    for (int i = 0; i < this->size(); i++) {
        for (int j = i + 1; j < this->size(); j++) {
            if (this->at(i).isSubsetOfThis(this->at(j))) {
                indexes.append(j);
            } else if (this->at(j).isSubsetOfThis(this->at(i))) {
                indexes.append(i);
            }
        }
    }
    qSort(indexes);
    for (int i = indexes.size() - 1; i >= 0; i--) {
        this->removeAt(indexes[i]);
    }
}

MultiSet &MultiSet::operator|=(int value)
{
    *this |= Set(value);
    return *this;
}

MultiSet &MultiSet::operator|=(const Set &other)
{
    for (int i = 0; i < this->size(); i++) {
        this->replace(i, this->at(i) | other);
    }
    return *this;
}

MultiSet &MultiSet::operator&=(int value)
{
    *this &= Set(value);
    return *this;
}

MultiSet &MultiSet::operator&=(const Set &other)
{
    for (int i = 0; i < this->size(); i++) {
        this->replace(i, this->at(i) & other);
    }
    return *this;
}

void MultiSet::display()
{
    printf("{");
    for (int i = 0; i < this->size(); i++) {
        this->at(i).display();
        if (i < this->size() - 1) {
            printf(",");
        }
    }
    printf("}\r\n");
}
