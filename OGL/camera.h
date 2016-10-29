#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QWidget>
#include <QVector3D>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QtMath>
#include <QMatrix4x4>
#include <iostream>


enum class CameraDirection{FORWARD, BACKWARD, LEFT, RIGHT};
enum class CameraOrientation{UP, DOWN, LEFT, RIGHT};

class Camera
{
public:
    static constexpr GLfloat YAW = -90.0f;
    static constexpr GLfloat PITCH = 0.0f;
    static constexpr GLfloat SPEED = 3.0f;
    static constexpr GLfloat SENSITIVITY = 0.25f;
    static constexpr GLfloat ZOOM = 45.0f;

    Camera(QVector3D position);
    /*
    Camera(QVector3D position = QVector3D(0.0f, 0.0f, 0.0f),
           QVector3D up = QVector3D(0.0f, 1.0f, 0.0f),
           GLfloat yaw = Camera::YAW,
           GLfloat pitch = Camera::PITCH);
           */
    void updateCameraVectors();
    QMatrix4x4 getViewMatrix();
    void processMovement(CameraDirection dir);
    void processOrientation(CameraOrientation orient);

private:
    QVector3D position;
    QVector3D front;
    QVector3D upCamera;
    QVector3D right;
    QVector3D upWorld;
    
    GLfloat yaw;
    GLfloat pitch;
    
    GLfloat movementSpeed;
    
};

#endif // CAMERA_H
