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
            const QStringList &tableGContent,
            bool displayOn = true
            ); // Для отладки
    PaulAngerMinimizer(
            const QString &jumpTableFileName,
            const QString &outputTableFileName,
            bool displayOn = true
            ); // Для релизной версии, которая читает данные из файла

    QString resultString() const;

    void setDisplayOn(bool displayOn);

    bool isGoodVariant() const;

private:
    MultiSet Lm; // Итоговый список множеств
    bool m_displayOn;

    void mainProcess(
            const QStringList &tableFContent,
            const QStringList &tableGContent
            );
};

#endif // PAULANGERMINIMIZER_H
