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
    magnitude = 0.0;
}

Vector::Vector(GLdouble x, GLdouble y, GLdouble z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
    magnitude = sqrt(x * x + y * y + z * z);
}
Vector::Vector(const Vector &v) {
    components[0] = v.components[0];
    components[1] = v.components[1];
    components[2] = v.components[2];
    magnitude = v.magnitude;
}

GLdouble Vector::x() const {
    return components[0];
}
GLdouble Vector::y() const {
    return components[1];
}
GLdouble Vector::z() const {
    return components[2];
}

GLdouble Vector::length() const {
    return magnitude;
}
void Vector::normalize() {
    components[0] /= magnitude;
    components[1] /= magnitude;
    components[2] /= magnitude;
    magnitude = 1;
}

void Vector::setX(GLdouble x) {
    components[0] = x;
    recalculateLength();
}
void Vector::setY(GLdouble y) {
    components[1] = y;
    recalculateLength();
}
void Vector::setZ(GLdouble z) {
    components[2] = z;
    recalculateLength();
}

bool Vector::operator==(const Vector& rhs) const {
    return  (this->components[0] == rhs.components[0]) &&
    (this->components[1] == rhs.components[1]) &&
    (this->components[2] == rhs.components[2]);
}
bool Vector::operator!=(const Vector& rhs) const {
    return !(*this == rhs);
}

const Vector Vector::operator+() const {
    return *this;
}
Vector Vector::operator-() const {
    return Vector(-components[0], -components[1], -components[2]);
}
Vector Vector::operator+(const Vector& rhs) const {
    return Vector(this->components[0] + rhs.components[0],
                  this->components[1] + rhs.components[1],
                  this->components[2] + rhs.components[2]);
}
Vector Vector::operator-(const Vector& rhs) const {
    return Vector(this->components[0] - rhs.components[0],
                  this->components[1] - rhs.components[1],
                  this->components[2] - rhs.components[2]);
}
//Make this operation symmetrical
Vector Vector::operator*(GLdouble k) const {
    return Vector(this->components[0] * k,
                  this->components[1] * k,
                  this->components[2] * k);
}
Vector Vector::operator/(GLdouble k) const {
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
Vector& Vector::operator*=(const GLdouble& k) {
    *this = *this * k;
    return *this;
}
Vector& Vector::operator/=(const GLdouble& k) {
    *this = *this / k;
    return *this;
}

Vector Vector::normalizedVector() const {
    return *this / magnitude;
}
Vector Vector::projectionOnto(const Vector& v1) const {
    GLdouble lengthV1 = v1.magnitude;
    return (v1 * this->dot(v1)) / (lengthV1 * lengthV1);
}
Vector Vector::cross(const Vector& v1) const {
    GLdouble x = components[1] * v1.components[2] - components[2] * v1.components[1];
    GLdouble y = components[2] * v1.components[0] - components[0] * v1.components[2];
    GLdouble z = components[0] * v1.components[1] - components[1] * v1.components[0];
    return Vector(x, y, z);
}
GLdouble Vector::dot(const Vector& v1) const {
    GLdouble x = components[0] * v1.components[0];
    GLdouble y = components[1] * v1.components[1];
    GLdouble z = components[2] * v1.components[2];
    return x + y + z;
}
Vector Vector::ReflectedAcross(const Vector& axis) const {
    Vector ogUnit = this->normalizedVector();
    Vector axUnit = axis.normalizedVector();
    GLdouble coef = 2 * ogUnit.dot(axUnit);
    return ((axUnit * coef) - ogUnit) * magnitude;
}

void Vector::recalculateLength() {
    GLdouble x = components[0];
    GLdouble y = components[1];
    GLdouble z = components[2];
    magnitude = sqrt(x * x + y * y + z * z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    return out << "X:" << v.components[0] << std::endl
            << "Y:" << v.components[1] << std::endl
            << "Z:" << v.components[2] << std::endl
            << "Length:" << v.magnitude << std::endl;
}
