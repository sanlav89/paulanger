#ifndef JUMPTABLE_H
#define JUMPTABLE_H

#include "statetable.h"
#include <QPoint>

class JumpTable : public StateTable
{
public:
    JumpTable(const QStringList &states, const QString &title = QString());
    JumpTable(const QString &fileName, const QString &title = QString());
    QList<QPoint> compatibleStates(int col1, int col2) const;
};

#endif // JUMPTABLE_H
