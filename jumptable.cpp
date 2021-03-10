#include "jumptable.h"

JumpTable::JumpTable() : StateTable()
{

}

JumpTable::JumpTable(const QStringList &states, const QString &title) :
    StateTable(states, title)
{
}

QList<QPoint> JumpTable::compatibleStates(int col1, int col2) const
{
    QList<QPoint> result;
    for (int i = 0; i < this->size(); i++) {
        if (!this->at(i).at(col1).isIdleState()
                && !this->at(i).at(col2).isIdleState()
                && this->at(i).at(col1).state() != this->at(i).at(col2).state()) {
            result.append(QPoint(this->at(i).at(col1).state(),
                                 this->at(i).at(col2).state()));
        }
    }
    return result;
}
