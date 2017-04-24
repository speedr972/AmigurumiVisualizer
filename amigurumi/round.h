#ifndef ROUND_H
#define ROUND_H

#include <vector>
#include <string>
#include "stitch.h"

class Round
{
public:
    Round();
    int addStitch(Stitch stitch);
    void addStitches(Stitch stitch, int number);
    void clear();
    QString toString();
    void display();

    std::vector<Stitch> getStitchesSet() const;
    void setStitchesSet(const std::vector<Stitch> &value);

    std::vector<int> getNumberSet() const;
    void setNumberSet(const std::vector<int> &value);

    int getNbStitches() const;
    void setNbStitches(int value);

private:
    std::vector<Stitch> stitchesSet;
    std::vector<int> numberSet;
    int nbStitches;
};

#endif // ROUND_H
