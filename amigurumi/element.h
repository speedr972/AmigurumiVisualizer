#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include <iostream>
#include "amigurumi/round.h"
#include <QVector3D>
#include "OGL/modelelement.h"

class ModelElement;

class Element
{
public:
    Element();
    Element(QString s);
    ~Element();

    void display();
    QString toString();

    void addRound(Round round);
    void updateModel();

    QString getElementName() const;
    void setElementName(const QString &value);

    float getRotZ() const;
    void setRotZ(float value);

    float getRotY() const;
    void setRotY(float value);

    float getRotX() const;
    void setRotX(float value);

    QVector3D getPosition() const;
    void setPosition(const QVector3D &value);

    std::vector<Round> getRounds() const;
    void setRounds(const std::vector<Round> &value);

    int getMaxStitchesRound() const;
    void setMaxStitchesRound(int value);

    ModelElement *getModel() const;
    void setModel(ModelElement *value);

private:
    std::vector<Round> rounds;
    QVector3D position;
    float rotX;
    float rotY;
    float rotZ;
    QString elementName;
    int maxStitchesRound;
    ModelElement *model;
};

#endif // ELEMENT_H
