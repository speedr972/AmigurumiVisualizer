#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    /*
    QMenu *menuFile = menuBar()->addMenu("&File");
    QMenu *menuEdit = menuBar()->addMenu("&Edit");
    QMenu *menuHelp = menuBar()->addMenu("&Help");
    */

    QWidget *mainView = new QWidget;
    this->setCentralWidget(mainView);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainView->setLayout(mainLayout);

    ///////////////////////////////////////////////
    //left part
    QWidget *editorAreaWidget = new QWidget;
    QVBoxLayout *editorArea = new QVBoxLayout;
    editorAreaWidget->setLayout(editorArea);
    QTextEdit *editorTextEdit = new QTextEdit;

    QWidget *buttonsEditorAreaWidget = new QWidget;
    QHBoxLayout *buttonsEditorArea = new QHBoxLayout;
    QPushButton *openFileButton = new QPushButton;
    QPushButton *updateButton = new QPushButton;
    buttonsEditorArea->addWidget(openFileButton);
    buttonsEditorArea->addWidget(updateButton);
    buttonsEditorAreaWidget->setLayout(buttonsEditorArea);

    editorArea->addWidget(editorTextEdit);
    editorArea->addWidget(buttonsEditorAreaWidget);


    mainLayout->addWidget(editorAreaWidget);
    ///////////////////////////////////////////////


    //middle part

    //right part

}

