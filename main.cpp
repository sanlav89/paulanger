#include <QCoreApplication>
#include "jumptable.h"
#include "outputtable.h"
#include "advancedcompatibletable.h"
#include "fullcompatibletable.h"
#include "set.h"
#include "multiset.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList tableFContent;
    QStringList tableGContent;

    tableFContent << "- - 3 3 1 2"
                  << "- 1 4 5 2 -"
                  << "1 2 - 2 3 3"
                  << "- - 5 - - 2";
    tableGContent << "- - 1 1 - 1"
                  << "- 2 2 2 2 -"
                  << "2 - - 1 2 -"
                  << "- - 1 - - 1";

    JumpTable tableF(tableFContent, "Jump table");
    OutputTable tableG(tableGContent, "Output table");
    AdvancedCompatibleTable tableAC(&tableF, &tableG, "Advanced Compatible Table");
    FullCompatibleTable tableFC(&tableAC, "Full Compatible Table");

    tableF.display();
    tableG.display();
    tableAC.display();
    tableFC.display();

    // Минимизация таблицы совместимости
    MultiSet Lm; // Итоговый список множеств

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

    return a.exec();
}
