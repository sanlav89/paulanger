#ifndef OUTPUTTABLE_H
#define OUTPUTTABLE_H

#include "statetable.h"

class OutputTable : public StateTable
{
public:
    OutputTable();
    OutputTable(const QStringList &states, const QString &title = QString());
    bool isCompatibleByOutputs(int col1, int col2);
};

#endif // OUTPUTTABLE_H
