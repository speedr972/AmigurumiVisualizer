#ifndef MODELELEMENT_H
#define MODELELEMENT_H


#include <QMatrix4x4>
#include <QVector3D>
#include <QtMath>
#include "amigurumi/round.h"
#include "amigurumi/element.h"
#include <stdio.h>
#include <stdlib.h>

class Element;

class ModelElement
{
public:
    //ModelElement();
    ModelElement(Element *el);
    ~ModelElement();

    void update();


    int getSizeVertices() const;

    int getSizeNormals() const;

    int getSizeColors() const;

    int getSizeIndices() const;

    int getNbVertices() const;


    Element *e;

    QMatrix4x4 transformationMatrix;
    float *vertices;
    float *normals;
    float *colors;
    int *indices;

    int sizeVertices;
    int sizeNormals;
    int sizeColors;
    int sizeIndices;
    int nbVertices;
};

#endif // MODELELEMENT_H
