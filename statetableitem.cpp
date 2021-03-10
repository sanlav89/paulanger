#include "statetableitem.h"

StateTableItem::StateTableItem() : QVariant()
{
}

StateTableItem::StateTableItem(const QVariant &other) : QVariant(other)
{
}

StateTableItem::StateTableItem(const QString &stateStr) : QVariant()
{
    bool ok = false;
    int state = stateStr.toInt(&ok);
    if (stateStr == "-") {
        *this = QVariant(int(StateIdle));
    } else if (!ok) {
        *this = QVariant(int(StateError));
    } else {
        *this = QVariant(state);
    }
}

StateTableItem::StateTableItem(const int &state) : QVariant(state)
{
}

StateTableItem::StateTableItem(const QList<QPoint> &compatibleStates) :
    QVariant()
{
    QList<QVariant> compatibleStatesVariant;
    for (int i = 0; i < compatibleStates.size(); i++) {
        compatibleStatesVariant.append(QVariant(compatibleStates[i]));
    }
    *this = StateTableItem(compatibleStatesVariant);
}

StateTableItem::StateTableItem(const QList<QVariant> &variantList) :
    QVariant(variantList)
{
}

bool StateTableItem::isIdleState() const
{
    bool ok = false;
    int state = this->toInt(&ok);
    return (ok && state == StateIdle);
}

bool StateTableItem::isErrorState() const
{
    bool ok = false;
    int state = this->toInt(&ok);
    if (ok && state == StateError) {
        return true;
    } else if (!ok) {
        for (int i = 0; i < this->toList().size(); i++) {
            if (this->toList().at(i).toPoint() == QPoint()) {
                return true;
            }
        }
    }
    return false;
}

int StateTableItem::state() const
{
    bool ok = false;
    int state = this->toInt(&ok);
    return state;
}

QString StateTableItem::displayState() const
{
    if (isIdleState()) {
        return "  -";
    } else {
        return QString::asprintf("%3d", this->toInt());
    }
}

bool StateTableItem::isNotCompatible() const
{
    bool ok = false;
    int state = this->toInt(&ok);
    return (ok && state == StateNotCompatible);
}

QList<QPoint> StateTableItem::compatibleStates() const
{
    QList<QPoint> result;
    for (int i = 0; i < this->toList().size(); i++) {
        result.append(this->toList()[i].toPoint());
    }
    return result;
}

QString StateTableItem::displayCompatibleStates() const
{
    QString result;
    result.append("[");
    if (isNotCompatible()) {
        result.append("X");
    } else {
        for (int i = 0; i < compatibleStates().size(); i++) {
            result.append(QString::asprintf("%d,%d", compatibleStates()[i].x(),
                                                     compatibleStates()[i].y()));
            if (i < compatibleStates().size() - 1) {
                result.append(";");
            }
        }
    }
    result.append("]");
    return result;
}
