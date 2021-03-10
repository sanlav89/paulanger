#ifndef ADVANCEDCOMPATIBLETABLE_H
#define ADVANCEDCOMPATIBLETABLE_H

#include "statetable.h"
#include "jumptable.h"
#include "outputtable.h"

class AdvancedCompatibleTable : public StateTable
{
public:
    AdvancedCompatibleTable();
    AdvancedCompatibleTable(JumpTable *jumpTable, OutputTable *outputTable);
    void display() override;
};

#endif // ADVANCEDCOMPATIBLETABLE_H
