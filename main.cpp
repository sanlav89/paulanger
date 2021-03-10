#include <QCoreApplication>
#include "statetable.h"

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

    StateTable tableF(tableFContent, "Jump table");
    StateTable tableG(tableGContent, "Output table");

    tableF.display();
    tableG.display();

    return a.exec();
}
