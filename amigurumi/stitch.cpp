#include "stitch.h"

Stitch::Stitch(StitchType type)
{
    this->type = type;
}

QString Stitch::toString()
{
    switch (type) {
    case StitchType::SINGLE_CROCHET:
        return QString("sc");
        break;
    case StitchType::DOUBLE_CROCHET:
        return QString("dc");
        break;
    case StitchType::INCREASE:
        return QString("inc");
        break;
    case StitchType::DECREASE:
        return QString("dec");
        break;
    case StitchType::SLIP_STITCH:
        return QString("slip stitch");
        break;
    case StitchType::CHAIN:
        return QString("ch");
        break;
    default:
        break;
    }
}

void Stitch::display()
{
    QString s = this->toString();
    std::cout << s.toStdString();
}

StitchType Stitch::getType() const
{
    return type;
}

void Stitch::setType(const StitchType &value)
{
    type = value;
}
