#ifndef ADVANCEDCOMPATIBLETABLE_H
#define ADVANCEDCOMPATIBLETABLE_H

#include "statetable.h"
#include "jumptable.h"
#include "outputtable.h"

class AdvancedCompatibleTable : public StateTable
{
public:
    AdvancedCompatibleTable(const QString &title = QString());
    AdvancedCompatibleTable(
            JumpTable *jumpTable,
            OutputTable *outputTable,
            const QString &title = QString()
            );
    int colCount() const;
    void display() override;
};

#endif // ADVANCEDCOMPATIBLETABLE_H
