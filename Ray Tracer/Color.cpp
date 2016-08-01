//
//  Color.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include <cmath>
#include "Color.hpp"

Color::Color() {
    _components[0] = 0x10;
    _components[1] = 0x00;
    _components[2] = 0x00;
    _components[3] = 0xFF;
}

Color::Color(GLint r, GLint g, GLint b, GLint a) {
    _components[0] = r;
    _components[1] = g;
    _components[2] = b;
    _components[3] = a;
}

GLint Color::R() {
    return _components[0];
}
GLint Color::G() {
    return _components[1];
}
GLint Color::B() {
    return _components[2];
}
GLint Color::A() {
    return _components[3];
}

void Color::Clamp() {
    _components[0] = fmin(255, _components[0]);
    _components[1] = fmin(255, _components[1]);
    _components[2] = fmin(255, _components[2]);
    _components[3] = fmin(255, _components[3]);
}

// This addition and subtraction are simple and don't account for transparency.
Color Color::operator+(const Color& rhs) const {
    return Color(this->_components[0] + rhs._components[0],
                  this->_components[1] + rhs._components[1],
                  this->_components[2] + rhs._components[2],
                    0xFF);
}
Color Color::operator-(const Color& rhs) const {
    return Color(this->_components[0] - rhs._components[0],
                  this->_components[1] - rhs._components[1],
                  this->_components[2] - rhs._components[2],
                    0xFF);
}
Color Color::operator*(const Color& rhs) const {
    return Color((this->_components[0] * rhs._components[0]) / 255,
                  (this->_components[1] * rhs._components[1]) / 255,
                  (this->_components[2] * rhs._components[2]) / 255,
                    0xFF);
}
Color Color::operator*(GLdouble k) const {
    return Color(this->_components[0] * k,
                 this->_components[1] * k,
                 this->_components[2] * k,
                 0xFF);
}

Color& Color::operator+=(const Color& rhs) {
    *this = *this + rhs;
    return *this;
}
Color& Color::operator-=(const Color& rhs) {
    *this = *this - rhs;
    return *this;
}
Color& Color::operator*=(const Color& rhs) {
    *this = *this * rhs;
    return *this;
}
Color& Color::operator*=(GLdouble k) {
    *this = *this * k;
    return *this;
}
