#ifndef MODELELEMENT_H
#define MODELELEMENT_H


#include <QMatrix4x4>
#include <QVector3D>
#include <QtMath>
#include "amigurumi/round.h"
#include "amigurumi/element.h"

class Element;

class ModelElement
{
public:
    //ModelElement();
    ModelElement(Element *el);
    ~ModelElement();

    void update();


private:
    Element *e;

    QMatrix4x4 transformationMatrix;
    float *vertices;
    float *normals;
    float *colors;
    int *indices;
};

#endif // MODELELEMENT_H
