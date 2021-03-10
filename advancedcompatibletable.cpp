#include "advancedcompatibletable.h"

AdvancedCompatibleTable::AdvancedCompatibleTable() : StateTable()
{
}

AdvancedCompatibleTable::AdvancedCompatibleTable(
        JumpTable *jumpTable,
        OutputTable *outputTable
        ) :
     StateTable()
{
    for (int i = 0; i < outputTable->colCount(); i++) {
        QList<StateTableItem> rowStates;
        for (int j = 0; j < outputTable->colCount(); j++) {
            rowStates.append(StateTableItem());
        }
        this->append(rowStates);
    }

    for (int j = 0; j < outputTable->colCount(); j++) {
        QList<StateTableItem> rowStates = this->at(j);
        for (int i = j + 1; i < outputTable->colCount(); i++) {
            if (outputTable->isCompatibleByOutputs(j, i)) {
                rowStates.replace(i, StateTableItem(jumpTable->compatibleStates(j, i)));
            } else {
                rowStates.replace(i, QVariant(StateTableItem::StateNotCompatible));
            }
        }
        this->replace(j, rowStates);
    }
}

void AdvancedCompatibleTable::display()
{
    int colCount = 0;
    if (this->size() <= 0) {
        return;
    } else {
        colCount = this->at(0).size();
    }
    printf("\r\n");
    for (int i = 0; i < colCount; i++) {
        for (int j = 0; j < i; i++) {
            printf("%8s", this->at(j).at(i).displayCompatibleStates().toLocal8Bit().data());
        }
        printf("\r\n");
    }
}