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
        if (this->at(i).at(col1) != IDLE_STATE
                && this->at(i).at(col2) != IDLE_STATE
                && this->at(i).at(col1) != this->at(i).at(col2)) {
            return false;
        }
    }
    return true;
}
