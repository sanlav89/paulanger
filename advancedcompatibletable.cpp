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
    // Заполнение пустыми
    for (int i = 0; i < outputTable->colCount(); i++) {
        QList<StateTableItem> rowStates;
        for (int j = 0; j < outputTable->colCount(); j++) {
            rowStates.append(QVariant(StateTableItem::StateEmpty));
        }
        this->append(rowStates);
    }

    //
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

int AdvancedCompatibleTable::colCount() const
{
    int result = 0;
    if (this->size() > 0) {
        result = this->at(0).size();
    }
    return result;
}

void AdvancedCompatibleTable::display()
{
    printf("%s\r\n", title().toLocal8Bit().data());
    for (int i = 1; i < colCount(); i++) {
        printf("%2d : ", i + 1);
        for (int j = 0; j < i; j++) {
            printf("%10s", this->at(j).at(i).displayCompatibleStates().toLocal8Bit().data());
        }
        printf("\r\n");
    }
}
