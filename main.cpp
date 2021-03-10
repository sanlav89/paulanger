#include <QCoreApplication>
#include "jumptable.h"
#include "outputtable.h"
#include "advancedcompatibletable.h"

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
    AdvancedCompatibleTable tableAC(&tableF, &tableG);

    tableF.display();
    tableG.display();
    tableAC.display();

    qDebug() << tableG.isCompatibleByOutputs(0, 3) << tableG.isCompatibleByOutputs(0, 1);

    return a.exec();
}
