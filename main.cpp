#include <QCoreApplication>
#include "jumptable.h"
#include "outputtable.h"
#include "advancedcompatibletable.h"
#include "fullcompatibletable.h"

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

    return a.exec();
}
