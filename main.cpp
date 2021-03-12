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

    MultiSet Lm;
    Lm.addSet(Set(tableFC.colCount()));

    for (int i = tableFC.colCount() - 2; i >= 0; i--) {
        Set currentSet;
        for (int j = tableFC.colCount() - 1; j > i; j--) {
            if (!tableFC.at(i).at(j).isNotCompatible()) {
                currentSet.addNew(Set(j + 1));
            }
            qDebug() << i + 1 << j + 1 << tableFC.at(i).at(j).isNotCompatible()
                     << tableFC.at(i).at(j).displayCompatibleStates();
        }
        printf("Current set: ");
        currentSet.display();
        printf("\r\n");

        MultiSet LmTmp = Lm;
        LmTmp &= currentSet;
        LmTmp |= Set(i + 1);
        LmTmp.minimize();

        printf("LmTmp: ");
//        LmTmp.display();

        Lm.addMultiSet(LmTmp);
        Lm.minimize();
        Lm.display();
    }

//    QList<QVariant> tmp;
//    tmp.append(4);
//    tmp.append(6);
//    Lm.addNew(tmp);

//    Lm.display();

    MultiSet ms1;
    ms1.addSet(Set(5));
    ms1.addSet(Set());
    ms1 |= Set(3);
//    Set s1(6);
//    ms1 &= s1;
//    ms1 |= Set(5);
//    ms1.addNew(6);
//    ms1.minimize();

    ms1.display();







    return a.exec();
}
