#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QMatrix4x4>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <QKeyEvent>
#include "camera.h"
#include "amigurumi/amigurumi.h"
#include <QTimer>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLDisplayWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLDisplayWidget(QWidget *parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    ~GLDisplayWidget();

public slots:
    void cleanUp();
    void timeOutSlot();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;

    void applyMovement();

private:
    boolean keys[8];

    int m_fps_base;

    QTimer *m_timer;

    Camera m_camera;

    QOpenGLShaderProgram *m_program;

    QOpenGLVertexArrayObject m_xAxisVao;
    QOpenGLVertexArrayObject m_yAxisVao;
    QOpenGLVertexArrayObject m_zAxisVao;
    QOpenGLVertexArrayObject m_triangleVao;

    QOpenGLBuffer m_xAxisVbo;
    QOpenGLBuffer m_yAxisVbo;
    QOpenGLBuffer m_zAxisVbo;
    QOpenGLBuffer m_triangleVbo;

    GLuint m_locationProjectionMatrix;
    GLuint m_locationViewMatrix;
    GLuint m_locationModelMatrix;

    QMatrix4x4 m_projectionMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_modelMatrix;

    Amigurumi *a;

};

#endif // GLDISPLAYWIDGET_H
