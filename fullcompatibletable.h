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
};

#endif // FULLCOMPATIBLETABLE_H
