#ifndef AMIGURUMI_H
#define AMIGURUMI_H

#include "amigurumi/element.h"
#include <iostream>
#include <vector>

class Amigurumi
{
public:
    Amigurumi();
    void display();
    QString toString();

    void addElements(Element e);

    std::vector<Element> getElements() const;
    void setElements(const std::vector<Element> &value);

private:
    std::vector<Element> elements;

};

#endif // AMIGURUMI_H
