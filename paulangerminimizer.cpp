#include "paulangerminimizer.h"

PaulAngerMinimizer::PaulAngerMinimizer(
        const QStringList &tableFContent,
        const QStringList &tableGContent,
        bool displayOn
        ) :
    m_displayOn(displayOn)
{
    mainProcess(tableFContent, tableGContent);
}

PaulAngerMinimizer::PaulAngerMinimizer(
        const QString &jumpTableFileName,
        const QString &outputTableFileName,
        bool displayOn
        ) :
    m_displayOn(displayOn)
{
    mainProcess(StateTable::contentFromFile(jumpTableFileName),
                StateTable::contentFromFile(outputTableFileName));
}

QString PaulAngerMinimizer::resultString() const
{
    return Lm.toString();
}

void PaulAngerMinimizer::setDisplayOn(bool displayOn)
{
    m_displayOn = displayOn;
}

bool PaulAngerMinimizer::isGoodVariant() const
{
    if (Lm.size() == 4) {
        int cnt2 = 0;
        int cnt3 = 0;
        for (int i = 0; i < Lm.size(); i++) {
            if (Lm.at(i).size() == 2) {
                cnt2++;
            } else if (Lm.at(i).size() == 3) {
                cnt3++;
            }
        }
        return (cnt2 == 2 && cnt3 == 2);
    } else {
        return false;
    }
}

void PaulAngerMinimizer::mainProcess(const QStringList &tableFContent, const QStringList &tableGContent)
{
    JumpTable tableF(tableFContent, "Jump table");
    if (m_displayOn) {
        tableF.display();
    }
    OutputTable tableG(tableGContent, "Output table");
    if (m_displayOn) {
        tableG.display();
    }
    AdvancedCompatibleTable tableAC(&tableF, &tableG, "Advanced Compatible Table");
    if (m_displayOn) {
        tableAC.display();
    }
    FullCompatibleTable tableFC(&tableAC, "Full Compatible Table");
    if (m_displayOn) {
        tableFC.display();
    }

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

    if (m_displayOn) {
        printf("Result List: \r\n");
        Lm.display();
    }
}
