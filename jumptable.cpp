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
        int state1 = this->at(i).at(col1).state();
        int state2 = this->at(i).at(col2).state();
        if (!this->at(i).at(col1).isIdleState()
                && !this->at(i).at(col2).isIdleState()
                && state1 != state2) {

            // Сортировка состояний в паре по возрастанию
            QPoint p(state1, state2);
            if (state1 > state2) {
                p = QPoint(state2, state1);
            }

            // Добавление неповторяющейся пары
            if (!result.contains(p)) {
                result.append(p);
            }
        }
    }
    return result;
}
