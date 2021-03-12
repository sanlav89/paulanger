#ifndef STATETABLEITEM_H
#define STATETABLEITEM_H

#include <QVariant>
#include <QPoint>

class StateTableItem : public QVariant
{
public:

    enum SpecialStates {
        StateIdle = -1, // для таблиц переходов и выходов
        StateError = -2, // для всех
        StateNotCompatible = -3, // для таблиц совместимостей
        StateEmpty = -4 // // для таблиц совместимостей
    };

    StateTableItem();
    StateTableItem(const QVariant &other);
    StateTableItem(const QString &stateStr);
    StateTableItem(const int &state);
    StateTableItem(const QList<QPoint> &compatibleStates);
    StateTableItem(const QList<QVariant> &variantList);

    // для таблиц переходов и выходов
    bool isIdleState() const;
    bool isErrorState() const;
    int state() const;
    QString displayState() const;

    // для таблиц совместимостей
    bool isNotCompatible() const;
    bool isEmpty() const;
    QList<QPoint> compatibleStates() const;
    QString displayCompatibleStates() const;


};

#endif // STATETABLEITEM_H
