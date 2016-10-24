#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QMatrix4x4>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLDisplayWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLDisplayWidget(QWidget *parent=0);
    ~GLDisplayWidget();

public slots:
    void cleanUp();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;



private:
    QOpenGLShaderProgram *m_program;

    QOpenGLVertexArrayObject m_xAxisVao;
    QOpenGLVertexArrayObject m_yAxisVao;
    QOpenGLVertexArrayObject m_zAxisVao;

    QOpenGLBuffer m_xAxisVbo;
    QOpenGLBuffer m_yAxisVbo;
    QOpenGLBuffer m_zAxisVbo;

    GLuint m_locationProjectionMatrix;
    GLuint m_locationViewMatrix;
    GLuint m_locationModelMatrix;

    QMatrix4x4 m_projectionMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_modelMatrix;

};

#endif // GLDISPLAYWIDGET_H
