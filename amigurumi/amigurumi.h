#ifndef AMIGURUMI_H
#define AMIGURUMI_H

#include "amigurumi/element.h"
#include <iostream>
#include <vector>
#include <string>

class Amigurumi
{
public:
    Amigurumi();


    void display();
    QString toString();

    void addElements(Element *e);
    void deleteElement(Element *e);
    void clearElements();


    std::vector<Element*> elements;

};

#endif // AMIGURUMI_H
