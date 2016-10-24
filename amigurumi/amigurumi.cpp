#include "amigurumi.h"

Amigurumi::Amigurumi()
{

}

void Amigurumi::display()
{
    QString s = this->toString();
    std::cout << s.toStdString();
}

QString Amigurumi::toString()
{
    QString s = "";
    for(int i = 0; i<elements.size(); i++){
        s.append(elements.at(i).toString());
        s.append("\n-----------------------\n");
    }
    return s;
}

void Amigurumi::addElements(Element e)
{
    elements.push_back(e);
}

std::vector<Element> Amigurumi::getElements() const
{
    return elements;
}

void Amigurumi::setElements(const std::vector<Element> &value)
{
    elements = value;
}
