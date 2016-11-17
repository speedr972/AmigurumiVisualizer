#include "amigurumi.h"

Amigurumi::Amigurumi()
{

}

void Amigurumi::display()
{
    QString qs = this->toString();
    std::string s = qs.toLocal8Bit().constData();
    std::cout << s;
    std::cout << std::endl;
}

QString Amigurumi::toString()
{
    QString s = "";
    std::cout << "Nb elements dans l'amigurumi :" << this->elements.size() << std::endl;
    for(int i = 0; i<this->elements.size(); i++){
        s.append(this->elements.at(i)->toString());
        s.append("\n-----------------------\n");
    }
    std::cout << "fin boucle Amigurumi::toString" << std::endl;
    return s;
}

void Amigurumi::addElements(Element *e)
{
    this->elements.push_back(e);
    std::cout << "addElements" << std::endl;
}
