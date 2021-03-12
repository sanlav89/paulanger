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

    // Заполнение состояниями несовместимости ("X")
    setAllCellsCompatible(advancedCompatibleTable,
                          advancedCompatibleTable->findNotCompatibleIndexes());
}

int FullCompatibleTable::maxStateNumber() const
{
    return colCount();
}

bool FullCompatibleTable::setCellNotCompatible(int j, int i)
{
    QList<StateTableItem> rowStates = this->at(j);
    if (!rowStates.at(i).isNotCompatible()) {
        rowStates.replace(i, QVariant(StateTableItem::StateNotCompatible));
        this->replace(j, rowStates);
        return true;
    }
    return false;
}

/*
 * Рекуррентная штука
 */
void FullCompatibleTable::setAllCellsCompatible(
        AdvancedCompatibleTable *advancedCompatibleTable,
        const QList<QPoint> &indexes
        )
{
    for (int i = 0; i < indexes.size(); i++) {
        setCellNotCompatible(indexes[i].x(), indexes[i].y());
        QList<QPoint> newIndexes = advancedCompatibleTable->findIndexesOfState(
                    QPoint(indexes[i].x() + 1, indexes[i].y() + 1));
        if (newIndexes.size() > 0) {
            setAllCellsCompatible(advancedCompatibleTable, newIndexes);
        }
    }
}
