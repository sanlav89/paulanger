#ifndef PAULANGERMINIMIZER_H
#define PAULANGERMINIMIZER_H

#include "advancedcompatibletable.h"
#include "fullcompatibletable.h"
#include "multiset.h"

class PaulAngerMinimizer
{
public:
    PaulAngerMinimizer(
            const QStringList &tableFContent,
            const QStringList &tableGContent
            ); // Для отладки
    PaulAngerMinimizer(
            const QString &jumpTableFileName,
            const QString &outputTableFileName
            ); // Для релизной версии, которая читает данные из файла

    QString resultString() const;

private:
    MultiSet Lm; // Итоговый список множеств

    void mainProcess(
            const QStringList &tableFContent,
            const QStringList &tableGContent
            );
};

#endif // PAULANGERMINIMIZER_H
