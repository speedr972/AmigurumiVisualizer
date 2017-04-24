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
    /*
    QApplication app(argc, argv);
    GLDisplayWidget widget;
    widget.show();
    return app.exec();
    */


    //testDefineComponentsPointers();

    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
    MainWindow w;
    w.show();
    return app.exec();
    //testAddDeleteComponents();


    //return app.exec();



    /*
    //testParserRound();
    testParser1();
    return 0;
    */

}


