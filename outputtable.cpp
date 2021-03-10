#include "outputtable.h"

OutputTable::OutputTable() : StateTable()
{
}

OutputTable::OutputTable(const QStringList &states, const QString &title) :
    StateTable(states, title)
{
}

bool OutputTable::isCompatibleByOutputs(int col1, int col2)
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
