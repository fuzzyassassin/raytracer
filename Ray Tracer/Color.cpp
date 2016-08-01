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
    components[0] = 0x10;
    components[1] = 0x00;
    components[2] = 0x00;
    components[3] = 0xFF;
}

Color::Color(GLint r, GLint g, GLint b, GLint a) {
    components[0] = r;
    components[1] = g;
    components[2] = b;
    components[3] = a;
}

GLint Color::r() {
    return components[0];
}
GLint Color::g() {
    return components[1];
}
GLint Color::b() {
    return components[2];
}
GLint Color::a() {
    return components[3];
}

void Color::Clamp() {
    components[0] = fmin(255, components[0]);
    components[1] = fmin(255, components[1]);
    components[2] = fmin(255, components[2]);
    components[3] = fmin(255, components[3]);
}

// This addition and subtraction are simple and don't account for transparency.
Color Color::operator+(const Color& rhs) const {
    return Color(this->components[0] + rhs.components[0],
                  this->components[1] + rhs.components[1],
                  this->components[2] + rhs.components[2],
                    0xFF);
}
Color Color::operator-(const Color& rhs) const {
    return Color(this->components[0] - rhs.components[0],
                  this->components[1] - rhs.components[1],
                  this->components[2] - rhs.components[2],
                    0xFF);
}
Color Color::operator*(const Color& rhs) const {
    return Color((this->components[0] * rhs.components[0]) / 255,
                  (this->components[1] * rhs.components[1]) / 255,
                  (this->components[2] * rhs.components[2]) / 255,
                    0xFF);
}
Color Color::operator*(GLdouble k) const {
    return Color(this->components[0] * k,
                 this->components[1] * k,
                 this->components[2] * k,
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
