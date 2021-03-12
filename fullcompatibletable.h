#ifndef FULLCOMPATIBLETABLE_H
#define FULLCOMPATIBLETABLE_H

#include "advancedcompatibletable.h"

class FullCompatibleTable : public AdvancedCompatibleTable
{
public:
    FullCompatibleTable(const QString &title = QString());
    FullCompatibleTable(
            AdvancedCompatibleTable *advancedCompatibleTable,
            const QString &title = QString()
            );
    int maxStateNumber() const;

private:
    bool setCellNotCompatible(int j, int i);

    void setAllCellsCompatible(
            AdvancedCompatibleTable *advancedCompatibleTable,
            const QList<QPoint> &indexes
            );
};

#endif // FULLCOMPATIBLETABLE_H
