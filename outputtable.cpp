#include "outputtable.h"

OutputTable::OutputTable(const QStringList &states, const QString &title) :
    StateTable(states, title)
{
}

OutputTable::OutputTable(const QString &flieName, const QString &title) :
    StateTable(flieName, title)
{
}

bool OutputTable::isCompatibleByOutputs(int col1, int col2) const
{
    for (int i = 0; i < this->size(); i++) {
        if (!this->at(i).at(col1).isIdleState()
                && !this->at(i).at(col2).isIdleState()
                && this->at(i).at(col1).state() != this->at(i).at(col2).state()) {
            return false;
        }
    }
    return true;
}

int OutputTable::colCount() const
{
    if (this->size() > 0) {
        return this->at(0).size();
    }
    return 0;
}

int OutputTable::rowCount() const
{
    return this->size();
}
