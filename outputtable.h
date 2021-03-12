#ifndef OUTPUTTABLE_H
#define OUTPUTTABLE_H

#include "statetable.h"

class OutputTable : public StateTable
{
public:
    OutputTable(const QStringList &states, const QString &title = QString());
    OutputTable(const QString &fileName, const QString &title = QString());
    bool isCompatibleByOutputs(int col1, int col2) const;
    int rowCount() const;
    int colCount() const;
};

#endif // OUTPUTTABLE_H
