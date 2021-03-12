#include <QCoreApplication>
#include "paulangerminimizer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// ------ Версия с чтением входных файлов --------------------------------------
//    PaulAngerMinimizer pam(a.arguments()[1], a.arguments()[2]);

// ------ Версия с формированием контента таблиц здесь -------------------------
    QStringList tableFContent;
    QStringList tableGContent;

//    tableFContent << "- - 3 3 2 1"
//                  << "- 1 4 5 - 2"
//                  << "1 6 - 2 3 3"
//                  << "- - 5 - 2 -";

//    tableGContent << "- - 1 1 1 -"
//                  << "- 2 2 2 - 2"
//                  << "2 - - 1 - 2"
//                  << "- - 1 - 1 -";

//    tableFContent << "- 3 - 3 1 2"
//                  << "- 4 1 5 2 -"
//                  << "6 - 2 2 3 3"
//                  << "- 5 - - - 2";
//    tableGContent << "- 1 - 1 - 1"
//                  << "- 2 2 2 2 -"
//                  << "2 - - 1 2 -"
//                  << "- 1 - - - 1";

//    tableFContent << "3 - - 3 1 2"
//                  << "4 - 1 5 2 -"
//                  << "- 1 2 2 6 3"
//                  << "5 - - - - 2";
//    tableGContent << "1 - - 1 - 1"
//                  << "2 - 2 2 2 -"
//                  << "- 2 - 1 2 -"
//                  << "1 - - - - 1";

//    tableFContent << "- - 3 3 1 2"
//                  << "- 1 4 5 2 -"
//                  << "1 2 - 2 3 3"
//                  << "- - 5 - - 2";
//    tableGContent << "- - 1 1 - 1"
//                  << "- 2 2 2 2 -"
//                  << "2 - - 1 2 -"
//                  << "- - 1 - - 1";

//    tableFContent << "- 3 - 3 1 2"
//                  << "- 4 1 5 2 -"
//                  << "1 - 2 2 6 3"
//                  << "- 5 - - - 2";
//    tableGContent << "- 1 - 1 - 1"
//                  << "- 2 2 2 2 -"
//                  << "2 - - 1 2 -"
//                  << "- 1 - - - 1";

//    tableFContent << "3 2 - - 3 1"
//                  << "5 - - 1 4 2"
//                  << "2 3 1 2 - 3"
//                  << "- 2 - - 5 -";

//    tableGContent << "1 1 - - 1 -"
//                  << "2 - - 2 2 2"
//                  << "1 - 2 - - 2"
//                  << "- 1 - - 1 -";

//    tableFContent << "  -  -  3  2  1  3" << "  6  1  4  -  2  5" << "  1  2  -  3  3  2" << "  -  -  5  2  -  -";
//    tableGContent << "  -  -  1  1  -  1" << "  -  2  2  -  2  2" << "  2  -  -  -  2  1" << "  -  -  1  1  -  -";
    tableFContent << "  -  -  3  3  1  2" << "  -  1  4  5  2  -" << "  1  2  -  2  3  3" << "  -  -  6  -  -  2";
    tableGContent << "  -  -  1  1  -  1" << "  -  2  2  2  2  -" << "  2  -  -  1  2  -" << "  -  -  1  -  -  1";
    PaulAngerMinimizer pam(tableFContent, tableGContent);

    return a.exec();
}
