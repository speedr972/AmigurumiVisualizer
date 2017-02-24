#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include "amigurumi/amigurumi.h"
#include "amigurumi/element.h"
#include "OGL/gldisplaywidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    Amigurumi currentAmigurumi;
    int selectedElement;




    //--------------------------------------------------------
    //GUI elements
    GLDisplayWidget* glWidget;
    QPushButton* updateButton;
    QTextEdit *editorTextEdit;
    QPushButton *openFileButton;


    //--------------------------------------------------------

signals:

public slots:
};

#endif // MAINWINDOW_H
