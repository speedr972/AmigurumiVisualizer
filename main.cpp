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
#include "tests/testsamigurumi.h"



int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    /*
    GLDisplayWidget widget;
    widget.show();
    */


    //testDefineComponentsPointers();
    //MainWindow w;
    //w.show();
    //testAddDeleteComponents();


    //return app.exec();

    testParser1();

    //testParserRound();
    return 0;

}


