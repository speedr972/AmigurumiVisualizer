#include "camera.h"


Camera::Camera(QVector3D position)
{
    this->position = position;
    this->upWorld = QVector3D(0.0f, 1.0f, 0.0f);
    this->yaw = 90.0f;
    this->pitch = 0.0f;
    this->front = QVector3D(0.0f, 0.0f, 1.0f);
    this->movementSpeed = 0.5f;
    this->updateCameraVectors();
}
/*
Camera::Camera(QVector3D position,
               QVector3D up,
               GLfloat yaw,
               GLfloat pitch)
{
    this->position = position;
    this->upWorld = up;
    this->yaw = yaw;
    this->pitch = pitch;
    this->front = QVector3D(0.0f, 0.0f, 1.0f);
    this->movementSpeed = Camera::SPEED;
    this->updateCameraVectors();
}
*/

void Camera::updateCameraVectors()
{
    //update
    QVector3D frontTemp;
    frontTemp.setX(qCos(qDegreesToRadians(this->yaw)) * qCos(qDegreesToRadians(this->pitch)));
    frontTemp.setY(qSin(qDegreesToRadians(this->pitch)));
    frontTemp.setZ(qSin(qDegreesToRadians(this->yaw)) * qCos(qDegreesToRadians(this->pitch)));

    std::cout;
    this->front = frontTemp;
    this->front.normalize();
    this->right = QVector3D::crossProduct(this->upWorld, this->front);
    this->right.normalize();
    this->upCamera = QVector3D::crossProduct(this->front, this->right);
    this->upCamera.normalize();
}

QMatrix4x4 Camera::getViewMatrix()
{
    QMatrix4x4 mat;

    QVector4D col0(this->right, -QVector3D::dotProduct(this->right, this->position));
    QVector4D col1(this->upCamera, -QVector3D::dotProduct(this->upCamera, this->position));
    QVector4D col2(this->front, -QVector3D::dotProduct(this->front, this->position));
    QVector4D col3(0.0f, 0.0f, 0.0f, 1.0);

    mat.setRow(0, col0);
    mat.setRow(1, col1);
    mat.setRow(2, col2);
    mat.setRow(3, col3);

    return mat;
}

void Camera::processMovement(CameraDirection dir)
{
    switch (dir) {
    case CameraDirection::FORWARD:
        this->position -= this->front*0.25f;
        break;
    case CameraDirection::BACKWARD:
        this->position += this->front*0.25f;
        break;
    case CameraDirection::LEFT:
        this->position -= this->right*0.25f;
        break;
    case CameraDirection::RIGHT:
        this->position += this->right*0.25f;
        break;
    default:
        break;
    }

    std::cout << "x : " << position.x() << ", y : " << position.y() << ", z : " <<position.z() << std::endl;
}

void Camera::processOrientation(CameraOrientation orient)
{
    switch (orient) {
    case CameraOrientation::UP:
        this->pitch += 1.0f;
        break;
    case CameraOrientation::DOWN:
        this->pitch -= 1.0f;
        break;
    case CameraOrientation::LEFT:
        this->yaw -= 1.0f;
        break;
    case CameraOrientation::RIGHT:
        this->yaw += 1.0f;
        break;
    default:
        break;
    }
    this->updateCameraVectors();

    std::cout << "pitch : " << this->pitch << ", yaw : " << this->yaw << std::endl;
}
