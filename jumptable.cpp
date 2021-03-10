#include "jumptable.h"

JumpTable::JumpTable() : StateTable()
{

}

JumpTable::JumpTable(const QStringList &states, const QString &title) :
    StateTable(states, title)
{
}
