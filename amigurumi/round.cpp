#include "round.h"

Round::Round()
{
    //stitchesSet.clear();
    //numberSet.clear();
    nbStitches = 0;
}

void Round::addStitch(Stitch stitch)
{
    if(stitchesSet.empty()){
        //if no stitches, we add the stitch and count 1 for this stitch
        stitchesSet.push_back(stitch);
        numberSet.push_back(1);
    }else{
        Stitch lastStitch = stitchesSet.at(stitchesSet.size()-1);
        if(stitch.getType() == lastStitch.getType()){
            //if the stitch is the same as the previous, only increase the count
            numberSet.at(numberSet.size()-1)++;
        }else{
            stitchesSet.push_back(stitch);
            numberSet.push_back(1);
        }
    }

}

void Round::addStitches(Stitch stitch, int number)
{
    for(int i = 0; i<number; i++){
        addStitch(stitch);
    }
    nbStitches += number;
}

void Round::clear()
{
    stitchesSet.clear();
    numberSet.clear();
    nbStitches = 0;
}

QString Round::toString()
{
    QString s = "";
    for(int i = 0; i<numberSet.size(); i++){
        s.append(std::to_string(numberSet.at(i)).c_str());
        s.append(" ");
        s.append(stitchesSet.at(i).toString());
        s.append(", ");
    }
    s.append("(");
    s.append(std::to_string(nbStitches).c_str());
    s.append(")");
    return s;
}

void Round::display()
{
    QString s = this->toString();
    std::cout << s.toStdString();
}

std::vector<Stitch> Round::getStitchesSet() const
{
    return stitchesSet;
}

void Round::setStitchesSet(const std::vector<Stitch> &value)
{
    stitchesSet = value;
}

std::vector<int> Round::getNumberSet() const
{
    return numberSet;
}

void Round::setNumberSet(const std::vector<int> &value)
{
    numberSet = value;
}

int Round::getNbStitches() const
{
    return nbStitches;
}

void Round::setNbStitches(int value)
{
    nbStitches = value;
}






