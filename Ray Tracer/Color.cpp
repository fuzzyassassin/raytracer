//
//  Color.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include "Color.hpp"

Color::Color() {
    components[0] = 0xAA;
    components[1] = 0x00;
    components[2] = 0x11;
    components[3] = 0x00;
}

Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    components[0] = r;
    components[1] = g;
    components[2] = b;
    components[3] = a;
}

GLfloat Color::r() {
    return components[0];
}
GLfloat Color::g() {
    return components[1];
}
GLfloat Color::b() {
    return components[2];
}
GLfloat Color::a() {
    return components[3];
}
