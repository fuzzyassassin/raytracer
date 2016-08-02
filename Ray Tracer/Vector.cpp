//
//  Vector.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/5/16.
//
//

#include "Vector.hpp"
#include <cmath>

Vector::Vector() {
    _components[0] = 0.0;
    _components[1] = 0.0;
    _components[2] = 0.0;
    _magnitude = 0.0;
}

Vector::Vector(GLdouble x, GLdouble y, GLdouble z) {
    _components[0] = x;
    _components[1] = y;
    _components[2] = z;
    _magnitude = sqrt(x * x + y * y + z * z);
}
Vector::Vector(const Vector &v) {
    _components[0] = v._components[0];
    _components[1] = v._components[1];
    _components[2] = v._components[2];
    _magnitude = v._magnitude;
}

GLdouble Vector::X() const {
    return _components[0];
}
GLdouble Vector::Y() const {
    return _components[1];
}
GLdouble Vector::Z() const {
    return _components[2];
}
GLdouble Vector::Length() const {
    return _magnitude;
}
void Vector::SetX(GLdouble x) {
    _components[0] = x;
    RecalculateLength();
}
void Vector::SetY(GLdouble y) {
    _components[1] = y;
    RecalculateLength();
}
void Vector::SetZ(GLdouble z) {
    _components[2] = z;
    RecalculateLength();
}

bool Vector::operator==(const Vector& rhs) const {
    return  (this->_components[0] == rhs._components[0]) &&
    (this->_components[1] == rhs._components[1]) &&
    (this->_components[2] == rhs._components[2]);
}
bool Vector::operator!=(const Vector& rhs) const {
    return !(*this == rhs);
}

const Vector Vector::operator+() const {
    return *this;
}
Vector Vector::operator-() const {
    GLdouble newX = std::abs(_components[0]) == 0.0 ? 0.0 : -_components[0];
    GLdouble newY = std::abs(_components[1]) == 0.0 ? 0.0 : -_components[1];
    GLdouble newZ = std::abs(_components[2]) == 0.0 ? 0.0 : -_components[2];
    return Vector(newX, newY, newZ);
}
Vector Vector::operator+(const Vector& rhs) const {
    return Vector(this->_components[0] + rhs._components[0],
                  this->_components[1] + rhs._components[1],
                  this->_components[2] + rhs._components[2]);
}
Vector Vector::operator-(const Vector& rhs) const {
    return Vector(this->_components[0] - rhs._components[0],
                  this->_components[1] - rhs._components[1],
                  this->_components[2] - rhs._components[2]);
}
//Make this operation symmetrical
Vector Vector::operator*(GLdouble k) const {
    return Vector(this->_components[0] * k,
                  this->_components[1] * k,
                  this->_components[2] * k);
}
Vector Vector::operator/(GLdouble k) const {
    return Vector(this->_components[0] / k,
                  this->_components[1] / k,
                  this->_components[2] / k);
}

Vector& Vector::operator+=(const Vector& v) {
    *this = *this + v;
    return *this;
}
Vector& Vector::operator-=(const Vector& v) {
    *this = *this - v;
    return *this;
}
Vector& Vector::operator*=(const GLdouble& k) {
    *this = *this * k;
    return *this;
}
Vector& Vector::operator/=(const GLdouble& k) {
    *this = *this / k;
    return *this;
}

void Vector::Normalize() {
    _components[0] /= _magnitude;
    _components[1] /= _magnitude;
    _components[2] /= _magnitude;
    _magnitude = 1;
}
Vector Vector::NormalizedVector() const {
    return *this / _magnitude;
}
Vector Vector::ProjectionOnto(const Vector& v1) const {
    GLdouble lengthV1 = v1._magnitude;
    return (v1 * this->Dot(v1)) / (lengthV1 * lengthV1);
}
Vector Vector::Cross(const Vector& v1) const {
    GLdouble x = _components[1] * v1._components[2] - _components[2] * v1._components[1];
    GLdouble y = _components[2] * v1._components[0] - _components[0] * v1._components[2];
    GLdouble z = _components[0] * v1._components[1] - _components[1] * v1._components[0];
    return Vector(x, y, z);
}
GLdouble Vector::Dot(const Vector& v1) const {
    GLdouble x = _components[0] * v1._components[0];
    GLdouble y = _components[1] * v1._components[1];
    GLdouble z = _components[2] * v1._components[2];
    return x + y + z;
}
Vector Vector::ReflectedAcross(const Vector& axis) const {
    Vector ogUnit = this->NormalizedVector();
    Vector axUnit = axis.NormalizedVector();
    GLdouble coef = 2 * ogUnit.Dot(axUnit);
    return ((axUnit * coef) - ogUnit) * _magnitude;
}

void Vector::RecalculateLength() {
    GLdouble x = _components[0];
    GLdouble y = _components[1];
    GLdouble z = _components[2];
    _magnitude = sqrt(x * x + y * y + z * z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    return out << "X:" << v._components[0] << std::endl
            << "Y:" << v._components[1] << std::endl
            << "Z:" << v._components[2] << std::endl
            << "Length:" << v._magnitude << std::endl;
}
