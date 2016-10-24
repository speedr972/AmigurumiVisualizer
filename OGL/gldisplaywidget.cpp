#include "gldisplaywidget.h"


GLDisplayWidget::GLDisplayWidget(QWidget *parent)
    :QOpenGLWidget(parent), m_program(0)
{
    this->setFixedSize(QSize(640, 480));
}

GLDisplayWidget::~GLDisplayWidget()
{
    cleanUp();
}



GLfloat dataXAxis[] = {
    //position        //colour
    0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f, 1.0f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
};

GLfloat dataYAxis[] = {
    //position        //colour
    0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f, 1.0f,
    0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
};

GLfloat dataZAxis[] = {
    //position        //colour
    0.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.1f, 1.0f,
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f
};

static const char *vertexShaderSourceCore =
    "#version 400 core\n"
    "in vec3 position;\n"
    "in vec4 colour;\n"

    "out vec4 pass_colour;\n"

    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 modelMatrix;\n"
    "uniform mat4 viewMatrix;\n"

    "void main() {\n"
    "   vec4 pos = vec4(position, 1.0);\n"
    "   gl_Position = projectionMatrix * viewMatrix *modelMatrix* pos;\n"
    "   pass_colour = colour;\n"
    "}\n";

static const char *fragmentShaderSourceCore =
    "#version 400 core\n"
    "in vec4 pass_colour;\n"
    "out vec4 fragColor;\n"
    "void main() {\n"
    "   fragColor = pass_colour;\n"
    "}\n";


void GLDisplayWidget::initializeGL()
{
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GLDisplayWidget::cleanUp);

    initializeOpenGLFunctions();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);


    this->m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore);
    m_program->bindAttributeLocation("position", 0);
    m_program->bindAttributeLocation("colour", 1);
    m_program->link();

    m_program->bind();
    m_locationProjectionMatrix = m_program->uniformLocation("projectionMatrix");
    m_locationViewMatrix= m_program->uniformLocation("viewMatrix");
    m_locationModelMatrix= m_program->uniformLocation("modelMatrix");

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    m_xAxisVao.create();
    m_xAxisVao.bind();
    m_xAxisVbo.create();
    m_xAxisVbo.bind();
    m_xAxisVbo.allocate(dataXAxis, 14*sizeof(GLfloat));
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    m_xAxisVbo.release();
    m_xAxisVao.release();

    m_yAxisVao.create();
    m_yAxisVao.bind();
    m_yAxisVbo.create();
    m_yAxisVbo.bind();
    m_yAxisVbo.allocate(dataYAxis, 14*sizeof(GLfloat));
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    m_yAxisVbo.release();
    m_yAxisVao.release();

    m_zAxisVao.create();
    m_zAxisVao.bind();
    m_zAxisVbo.create();
    m_zAxisVbo.bind();
    m_zAxisVbo.allocate(dataZAxis, 14*sizeof(GLfloat));
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7*sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    m_zAxisVbo.release();
    m_zAxisVao.release();

    m_program->release();
}


void GLDisplayWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(0.0f, 0.0f, -1.0f);
    m_modelMatrix.setToIdentity();


    m_program->bind();

    m_program->setUniformValue(m_locationModelMatrix, m_modelMatrix);
    m_program->setUniformValue(m_locationViewMatrix, m_viewMatrix);
    m_program->setUniformValue(m_locationProjectionMatrix, m_projectionMatrix);

    m_xAxisVao.bind();
    glDrawArrays(GL_LINES, 0, 2);
    m_xAxisVao.release();

    m_yAxisVao.bind();
    glDrawArrays(GL_LINES, 0, 2);
    m_yAxisVao.release();

    m_zAxisVao.bind();
    glDrawArrays(GL_LINES, 0, 2);
    m_zAxisVao.release();

    m_program->release();


}

void GLDisplayWidget::resizeGL(int width, int height)
{
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45.0f, GLfloat(width)/height, 0.01f, 100.0f);
}


void GLDisplayWidget::cleanUp()
{
    makeCurrent();
    m_xAxisVbo.destroy();
    m_yAxisVbo.destroy();
    m_zAxisVbo.destroy();
    delete m_program;
    m_program = 0;
    doneCurrent();
}


