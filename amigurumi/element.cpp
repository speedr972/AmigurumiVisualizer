#include "element.h"

Element::Element()
{
    elementName = "";
    position = QVector3D();
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    maxStitchesRound = 0;
    model = new ModelElement(this);
}

Element::Element(QString s)
{
    position = QVector3D();
    rotX = 0.0f;
    rotY = 0.0f;
    rotZ = 0.0f;
    elementName = s;
    maxStitchesRound = 0;
    model = new ModelElement(this);
}

Element::~Element()
{
    delete(model);
}

void Element::display()
{
    QString s = this->toString();
    std::cout << s.toStdString();
}

QString Element::toString()
{
   QString s =  "";
   s.append(elementName);
   s.append(", ");
   s.append(std::to_string(maxStitchesRound).c_str());
   s.append("\n");
   for(int i = 0; i<rounds.size(); i++){
      s.append(std::to_string(i+1).c_str());
      s.append(") ");
      s.append(rounds.at(i).toString());
      s.append("\n");
   }

   return s;
}

void Element::addRound(Round round)
{
    rounds.push_back(round);

    if(round.getNbStitches()>maxStitchesRound){
        maxStitchesRound = round.getNbStitches();
    }

}

void Element::updateModel()
{
    this->model->update();
}








QString Element::getElementName() const
{
    return elementName;
}

void Element::setElementName(const QString &value)
{
    elementName = value;
}

float Element::getRotZ() const
{
    return rotZ;
}

void Element::setRotZ(float value)
{
    rotZ = value;
}

float Element::getRotY() const
{
    return rotY;
}

void Element::setRotY(float value)
{
    rotY = value;
}

float Element::getRotX() const
{
    return rotX;
}

void Element::setRotX(float value)
{
    rotX = value;
}

QVector3D Element::getPosition() const
{
    return position;
}

void Element::setPosition(const QVector3D &value)
{
    position = value;
}

std::vector<Round> Element::getRounds() const
{
    return rounds;
}

void Element::setRounds(const std::vector<Round> &value)
{
    rounds = value;
}

int Element::getMaxStitchesRound() const
{
    return maxStitchesRound;
}

void Element::setMaxStitchesRound(int value)
{
    maxStitchesRound = value;
}

ModelElement *Element::getModel() const
{
    return model;
}

void Element::setModel(ModelElement *value)
{
    model = value;
}
