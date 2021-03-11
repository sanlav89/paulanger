#include "fullcompatibletable.h"

FullCompatibleTable::FullCompatibleTable(const QString &title) :
    AdvancedCompatibleTable(title)
{
}

FullCompatibleTable::FullCompatibleTable(
        AdvancedCompatibleTable *advancedCompatibleTable, const QString &title
        ) :
    AdvancedCompatibleTable(title)
{
    // Заполнение пустыми состояниями
    for (int i = 0; i < advancedCompatibleTable->colCount(); i++) {
        QList<StateTableItem> rowStates;
        for (int j = 0; j < advancedCompatibleTable->colCount(); j++) {
            rowStates.append(QVariant(StateTableItem::StateEmpty));
        }
        this->append(rowStates);
    }

    // Расставляем отметки "X"
    for (int i = 1; i < advancedCompatibleTable->colCount(); i++) {
        for (int j = 0; j < i; j++) {
            if (advancedCompatibleTable->at(j).at(i).isNotCompatible()) {
                // 1) Эсли это стостояние в новой таблице не отмечено X, отмечаем
                if (!this->at(j).at(i).isNotCompatible()) {
                    QList<StateTableItem> rowStates = this->at(j);
                    rowStates.replace(i, QVariant(StateTableItem::StateNotCompatible));
                    this->replace(j, rowStates);
                }
            }
        }
    }
}
