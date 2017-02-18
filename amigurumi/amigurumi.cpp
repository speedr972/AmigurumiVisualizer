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
    //std::cout << "fin boucle Amigurumi::toString" << std::endl;
    return s;
}

void Amigurumi::addElements(Element *e)
{
    QString elementName = e->getElementName();
    int indexToDelete = -1;

    Element *el;
    //Look for the corresponding element in the list
    for(int i = 0; i<this->elements.size(); i++){
        el = this->elements.at(i);
        if(el->getElementName() == e->getElementName()){
            indexToDelete = i;
            break;
        }
    }

    el = nullptr;
    if(indexToDelete!=-1){
        std::cout << "An element with this name already exists" << std::endl;
        return;
    }
    this->elements.push_back(e);
    //std::cout << "addElements" << std::endl;
}

void Amigurumi::deleteElement(Element *e)
{
    QString elementName = e->getElementName();
    int indexToDelete = -1;

    Element *el;
    //Look for the corresponding element in the list
    for(int i = 0; i<this->elements.size(); i++){
        el = this->elements.at(i);
        if(el->getElementName() == e->getElementName()){
            indexToDelete = i;
            break;
        }
    }

    el = nullptr;

    //if found, delete from the vector and from memory
    if(indexToDelete!=-1){
        this->elements.erase(this->elements.begin() + indexToDelete);
        delete(e);
    }
}

void Amigurumi::clearElements()
{
    for(int i = 0; i<this->elements.size(); i++){
        delete(this->elements.at(i));
    }
    this->elements.clear();
}
