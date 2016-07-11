//
//  Camera.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include "Camera.hpp"

Camera::Camera() {
    
}
Camera::Camera(Vector position, Vector direction, GLfloat imagePlaneDist) : _position(position), _direction(direction) {
    _planeDist = imagePlaneDist;
}

void Camera::MoveTo(Vector position) {
    _position = position;
}

void Camera::ChangeDirection(Vector direction) {
    _direction = direction;
}

void Camera::RenderScene(Scene scene) {
    
}
