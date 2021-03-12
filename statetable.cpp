#include "statetable.h"
#include <QFile>
#include <QTextStream>

StateTable::StateTable(const QStringList &states, const QString &title) :
    QList<QList<StateTableItem>>(),
    m_title(title)
{
    initFromStringList(states);
}

StateTable::StateTable(const QString &fileName, const QString &title) :
    QList<QList<StateTableItem>>(),
    m_title(title)
{
    initFromStringList(contentFromFile(fileName));
}

void StateTable::display()
{
    printf("%s\r\n", m_title.toLocal8Bit().data());
    for (int i = 0; i < this->size(); i++) {
        for (int j = 0; j < this->at(i).size(); j++) {
            printf("%s", this->at(i).at(j).displayState().toLocal8Bit().data());
        }
        printf("\r\n");
    }
}

QString StateTable::title() const
{
    return m_title;
}

void StateTable::setTitle(const QString &title)
{
    m_title = title;
}

QStringList StateTable::contentFromFile(const QString &fileName)
{
    QFile fin(fileName);
    QTextStream sin(&fin);
    QStringList result;
    if (!fin.open(QIODevice::ReadOnly)) {
        qDebug() << Q_FUNC_INFO << "Can't open file" << fileName;
    } else {
        while (!sin.atEnd()) {
            result.append(sin.readLine());
        }
        fin.close();
    }
    return result;
}

void StateTable::initFromStringList(const QStringList &states)
{
    int colSize = 0;
    for (int i = 0; i < states.size(); i++) {
        QList<StateTableItem> rowStates;
        QStringList rowStatesStr = states[i].split(" ", Qt::SkipEmptyParts);
        if (i == 0) {
            colSize = rowStatesStr.size();
        } else if (rowStatesStr.size() != colSize) {
            this->clear();
            qDebug() << Q_FUNC_INFO << "Wrong format of states row";
            return;
        }
        for (int j = 0; j < rowStatesStr.size(); j++) {
            StateTableItem sti(rowStatesStr[j]);
            if (sti.isErrorState()) {
                this->clear();
                qDebug() << Q_FUNC_INFO << "Wrong format of states cell" << i << j;
                return;
            }
            rowStates.append(sti);
        }
        this->append(rowStates);
    }
}
