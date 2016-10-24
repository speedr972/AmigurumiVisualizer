#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QWidget>
#include <QVector3D>

class Camera
{
public:
    Camera();
    Camera(QVector3D position);

    QMatrix4x4 getViewMatrix();
private:
    QVector3D x;
    QVector3D y;
    QVector3D z;

};

#endif // CAMERA_H
