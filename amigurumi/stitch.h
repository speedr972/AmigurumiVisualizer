#ifndef STITCH_H
#define STITCH_H

#include <iostream>
#include <QString>



enum class StitchType{SINGLE_CROCHET, DOUBLE_CROCHET, INCREASE, DECREASE, SLIP_STITCH, CHAIN};

class Stitch
{
public:
    Stitch(StitchType type);
    QString toString();
    void display();

    StitchType getType() const;
    void setType(const StitchType &value);

private:
    StitchType type;
};

#endif // STITCH_H
