//
//  Vector.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/5/16.
//
//

#include "Vector.hpp"

Vector::Vector() {
    components[0] = 0.0;
    components[1] = 0.0;
    components[2] = 0.0;
}

Vector::Vector(GLfloat x, GLfloat y, GLfloat z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}
Vector::Vector(const Vector &v) {
    components[0] = v.components[0];
    components[1] = v.components[1];
    components[2] = v.components[2];
}

GLfloat Vector::x() const {
    return components[0];
}
GLfloat Vector::y() const {
    return components[1];
}
GLfloat Vector::z() const {
    return components[2];
}

GLfloat Vector::length() {
    GLfloat size =  components[0] * components[0] +
    components[1] * components[1] +
    components[2] * components[2];
    return sqrt(size);
}
void Vector::normalize() {
    GLfloat size = this->length();
    components[0] /= size;
    components[1] /= size;
    components[2] /= size;
}

void Vector::setX(GLfloat x) {
    components[0] = x;
}
void Vector::setY(GLfloat y) {
    components[1] = y;
}
void Vector::setZ(GLfloat z) {
    components[2] = z;
}

bool Vector::operator==(const Vector& rhs) {
    return  (this->components[0] == rhs.components[0]) &&
    (this->components[1] == rhs.components[1]) &&
    (this->components[2] == rhs.components[2]);
}
bool Vector::operator!=(const Vector& rhs) {
    return !(*this == rhs);
}

const Vector Vector::operator+() const {
    return *this;
}
Vector Vector::operator-() const {
    return Vector(-components[0], -components[1], -components[2]);
}
Vector Vector::operator+(const Vector& rhs) {
    return Vector(this->components[0] + rhs.components[0],
                  this->components[1] + rhs.components[1],
                  this->components[2] + rhs.components[2]);
}
Vector Vector::operator-(const Vector& rhs) {
    return Vector(this->components[0] - rhs.components[0],
                  this->components[1] - rhs.components[1],
                  this->components[2] - rhs.components[2]);
}
Vector Vector::operator*(GLfloat k) {
    return Vector(this->components[0] * k,
                  this->components[1] * k,
                  this->components[2] * k);
}
Vector Vector::operator/(GLfloat k) {
    return Vector(this->components[0] / k,
                  this->components[1] / k,
                  this->components[2] / k);
}

Vector& Vector::operator+=(const Vector& v) {
    *this = *this + v;
    return *this;
}
Vector& Vector::operator-=(const Vector& v) {
    *this = *this - v;
    return *this;
}
Vector& Vector::operator*=(const GLfloat& k) {
    *this = *this * k;
    return *this;
}
Vector& Vector::operator/=(const GLfloat& k) {
    *this = *this / k;
    return *this;
}

Vector Vector::normalizedVector() {
    return *this / this->length();
}
Vector Vector::cross(const Vector& v1) {
    GLfloat x = components[1] * v1.components[2] - components[2] * v1.components[1];
    GLfloat y = components[2] * v1.components[0] - components[0] * v1.components[2];
    GLfloat z = components[0] * v1.components[1] - components[1] * v1.components[0];
    return Vector(x, y, z);
}
GLfloat Vector::dot(const Vector& v1) {
    GLfloat x = components[0] * v1.components[0];
    GLfloat y = components[1] * v1.components[1];
    GLfloat z = components[2] * v1.components[2];
    return x + y + z;
}