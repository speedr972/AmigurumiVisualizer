#include <QApplication>
#include <iostream>
#include "amigurumi/stitch.h"
#include "amigurumi/round.h"
#include "amigurumi/element.h"
#include "amigurumi/amigurumi.h"
#include "OGL/gldisplaywidget.h"
#include <stdio.h>
#include <stdlib.h>
#include "GUI/mainwindow.h"

void testDefineComponents();
void testDefineComponentsPointers();
void testAddDeleteComponents();
void testAddRemoveComponents();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*
    GLDisplayWidget widget;
    widget.show();
    */


    //testDefineComponentsPointers();
    MainWindow w;
    w.show();
    //testAddDeleteComponents();

    return app.exec();

}

void testAddDeleteComponents(){
    Stitch s1(StitchType::CHAIN);

    Round r1;
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 10);

    Element *e1 = new Element("Hello1");
    Element *e1bis = new Element("Hello1");
    Element *e2 = new Element("Hello2");
    Element *e2bis = new Element("Hello2");
    Element *e3 = new Element("Hello3");
    Element *e3bis = new Element("Hello3");
    Element *e4 = new Element("Hello4");

    Amigurumi a;
    a.addElements(e1);
    a.addElements(e2);
    a.addElements(e2);
    a.addElements(e3);
    a.addElements(e3bis);
    a.addElements(e4);

    std::cout << "Before delete" << std::endl;
    a.display();


    a.deleteElement(e3);
    a.deleteElement(e2);
    std::cout << "after delete" << std::endl;
    a.display();

    a.clearElements();
    std::cout << "after clear" << std::endl;
    a.display();


}

void testDefineComponents(){
    std::cout << std::endl << "-------------TEST STITCH-----------" << std::endl;
    Stitch s1(StitchType::CHAIN);
    Stitch s2(StitchType::DECREASE);
    Stitch s3(StitchType::DOUBLE_CROCHET);
    Stitch s4(StitchType::INCREASE);
    Stitch s5(StitchType::SINGLE_CROCHET);
    s1.display();
    std::cout << std::endl;
    s2.display();
    std::cout << std::endl;
    s3.display();
    std::cout << std::endl;
    s4.display();
    std::cout << std::endl;
    s5.display();
    std::cout << std::endl;

    std::cout << std::endl << "-------------TEST ROUND-----------" << std::endl;
    Round r1;
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 1);
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 1);
    r1.addStitches(Stitch(StitchType::INCREASE), 1);
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 2);

    Round r2;
    r2.addStitches(Stitch(StitchType::DOUBLE_CROCHET), 3);
    r2.addStitches(Stitch(StitchType::DECREASE), 3);

    Round r3;
    r3.addStitches(Stitch(StitchType::CHAIN), 3);
    r3.addStitches(Stitch(StitchType::SINGLE_CROCHET), 2);
    r3.addStitches(Stitch(StitchType::SINGLE_CROCHET), 4);

    r1.display();

    std::cout << std::endl << "-------------TEST ELEMENT-----------" << std::endl;
    Element e1("Hello1");
    e1.addRound(r1);
    e1.addRound(r2);
    e1.addRound(r3);
    e1.display();

    Element e2("Hello2");
    e2.addRound(r3);
    e2.addRound(r2);
    e2.display();

    Element e3("Hello3");
    e3.addRound(r1);
    e3.addRound(r1);
    e3.addRound(r1);
    e3.display();

    std::cout << std::endl << "-------------TEST AMIGURUMI-----------" << std::endl;
    Amigurumi a = Amigurumi();
    a.addElements(&e1);
    a.display();
    a.addElements(&e2);
    a.display();
    a.addElements(&e3);
    a.display();

    e1.updateModel();
    printf("%d vertices\n", e1.getModel()->getNbVertices());
    for(int i = 0; i<e1.getModel()->getNbVertices(); i++){
        printf("%f, %f, %f;\n", e1.getModel()->vertices[i*3], e1.getModel()->vertices[i*3+1], e1.getModel()->vertices[i*3+2]);
    }

    printf("\nNormals\n");
    for(int i = 0; i<e1.getModel()->getNbVertices(); i++){
        printf("%f, %f, %f;\n", e1.getModel()->normals[i*3], e1.getModel()->normals[i*3+1], e1.getModel()->normals[i*3+2]);
    }
}


void testDefineComponentsPointers(){
    std::cout << std::endl << "-------------TEST STITCH-----------" << std::endl;
    Stitch s1(StitchType::CHAIN);
    Stitch s2(StitchType::DECREASE);
    Stitch s3(StitchType::DOUBLE_CROCHET);
    Stitch s4(StitchType::INCREASE);
    Stitch s5(StitchType::SINGLE_CROCHET);
    s1.display();
    std::cout << std::endl;
    s2.display();
    std::cout << std::endl;
    s3.display();
    std::cout << std::endl;
    s4.display();
    std::cout << std::endl;
    s5.display();
    std::cout << std::endl;

    std::cout << std::endl << "-------------TEST ROUND-----------" << std::endl;
    Round r1;
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 1);
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 1);
    r1.addStitches(Stitch(StitchType::INCREASE), 1);
    r1.addStitches(Stitch(StitchType::SINGLE_CROCHET), 2);

    Round r2;
    r2.addStitches(Stitch(StitchType::DOUBLE_CROCHET), 3);
    r2.addStitches(Stitch(StitchType::DECREASE), 3);

    Round r3;
    r3.addStitches(Stitch(StitchType::CHAIN), 3);
    r3.addStitches(Stitch(StitchType::SINGLE_CROCHET), 2);
    r3.addStitches(Stitch(StitchType::SINGLE_CROCHET), 4);

    r1.display();

    std::cout << std::endl << "-------------TEST ELEMENT-----------" << std::endl;
    Element *e1 = new Element("Hello1");
    e1->addRound(r1);
    e1->addRound(r2);
    e1->addRound(r3);
    e1->display();

    Element *e2 = new Element("Hello2");
    e2->addRound(r3);
    e2->addRound(r2);
    e2->display();

    Element *e3 = new Element("Hello3");
    e3->addRound(r1);
    e3->addRound(r1);
    e3->addRound(r1);
    e3->display();

    std::cout << std::endl << "-------------TEST AMIGURUMI-----------" << std::endl;
    Amigurumi a = Amigurumi();
    a.addElements(e1);
    a.display();
    a.addElements(e2);
    a.display();
    a.addElements(e3);
    a.display();

    e1->updateModel();
    printf("%d vertices\n", e1->getModel()->getNbVertices());
    for(int i = 0; i<e1->getModel()->getNbVertices(); i++){
        printf("%f, %f, %f;\n", e1->getModel()->vertices[i*3], e1->getModel()->vertices[i*3+1], e1->getModel()->vertices[i*3+2]);
    }

    printf("\nNormals\n");
    for(int i = 0; i<e1->getModel()->getNbVertices(); i++){
        printf("%f, %f, %f;\n", e1->getModel()->normals[i*3], e1->getModel()->normals[i*3+1], e1->getModel()->normals[i*3+2]);
    }
}
