#ifndef JUMPTABLE_H
#define JUMPTABLE_H

#include "statetable.h"

class JumpTable : public StateTable
{
public:
    JumpTable();
    JumpTable(const QStringList &states, const QString &title = QString());
};

#endif // JUMPTABLE_H
