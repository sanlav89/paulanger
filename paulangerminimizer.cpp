#include "paulangerminimizer.h"

PaulAngerMinimizer::PaulAngerMinimizer(
        const QStringList &tableFContent,
        const QStringList &tableGContent
        )
{
    mainProcess(tableFContent, tableGContent);
}

PaulAngerMinimizer::PaulAngerMinimizer(
        const QString &jumpTableFileName,
        const QString &outputTableFileName
        )
{
    mainProcess(StateTable::contentFromFile(jumpTableFileName),
                StateTable::contentFromFile(outputTableFileName));
}

QString PaulAngerMinimizer::resultString() const
{
    return Lm.toString();
}

void PaulAngerMinimizer::mainProcess(const QStringList &tableFContent, const QStringList &tableGContent)
{
    JumpTable tableF(tableFContent, "Jump table");
    tableF.display();
    OutputTable tableG(tableGContent, "Output table");
    tableG.display();
    AdvancedCompatibleTable tableAC(&tableF, &tableG, "Advanced Compatible Table");
    tableAC.display();
    FullCompatibleTable tableFC(&tableAC, "Full Compatible Table");
    tableFC.display();

    // Минимизация таблицы совместимости
    // Первый шаг
    Lm.addSet(Set(tableFC.colCount()));

    // Последующие шаги (цикл по столбцам таблицы)
    for (int i = tableFC.colCount() - 2; i >= 0; i--) {

        // Формируется множество из совместимых по выходам состояний
        Set currentSet;
        for (int j = tableFC.colCount() - 1; j > i; j--) {
            if (!tableFC.at(i).at(j).isNotCompatible()) {
                currentSet.addNew(Set(j + 1));
            }
//            qDebug() << i + 1 << j + 1 << tableFC.at(i).at(j).isNotCompatible()
//                     << tableFC.at(i).at(j).displayCompatibleStates();
        }

        // Создается временный список множеств
        MultiSet LmTmp = Lm;
        LmTmp &= currentSet;
        LmTmp |= Set(i + 1);
        LmTmp.minimize();

        // Временный список добавляется в основной список множеств
        Lm.addMultiSet(LmTmp);
        Lm.minimize();
    }

    printf("Result List: \r\n");
    Lm.display();
}
