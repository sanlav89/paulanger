#ifndef STATETABLEITEM_H
#define STATETABLEITEM_H

#include <QVariant>
#include <QPoint>

class StateTableItem : public QVariant
{
public:

    enum SpecialStates {
        StateIdle = -1,
        StateError = -2,
        StateNotCompatible = -3,
        StateEmpty = -4
    };

    StateTableItem();
    StateTableItem(const QVariant &other);
    StateTableItem(const QString &stateStr);
    StateTableItem(const int &state);
    StateTableItem(const QList<QPoint> &compatibleStates);
    StateTableItem(const QList<QVariant> &variantList);

    bool isIdleState() const;
    bool isErrorState() const;
    int state() const;
    QString displayState() const;
    bool isNotCompatible() const;
    bool isEmpty() const;
    QList<QPoint> compatibleStates() const;
    QString displayCompatibleStates() const;


};

#endif // STATETABLEITEM_H
