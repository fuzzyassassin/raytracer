//
//  Light.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include <cassert>
#include <cmath>
#include "Common.h"
#include "Light.hpp"
#include "Shape.hpp"
#include "Ray.hpp"

Light::Light() {
    _position = Vector(10, 50, 8);
    _ambient = Color(255, 0, 0, 1);
    _diffuse = Color(0, 255, 0, 1);
    _specular = Color(0, 0, 255, 1);
}

Light::Light(Vector position, Color ambient, Color diffuse, Color specular) {
    _position = position;
    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
}

Vector Light::Position() const {
    return _position;
}
Color Light::Ambient() const {
    return _ambient;
}
Color Light::Diffuse() const {
    return _diffuse;
}
Color Light::Specular() const {
    return _specular;
}

Color Light::CalculateAmbient(const Material& mat) const {
    Color color = _ambient * mat.Ambient();
    return color;
}

Color Light::CalculateDiffuse(const Material& mat, const Vector& normal, const Vector& toLight) const {
    Vector normalNormd = normal.normalizedVector();
    Vector toLightNormd = toLight.normalizedVector();
    
    Color diffuse = _diffuse * mat.Diffuse() * fmax(0, normalNormd.dot(toLightNormd));
    
    return diffuse;
}

Color Light::CalculateSpecular(const Material& mat, const Vector& normal, const Vector& toLight, const Vector& incoming) const {    
    Vector halfway = (toLight - incoming).normalizedVector();
    
    Color specular = _specular * mat.Specular() * pow(normal.normalizedVector().dot(halfway), mat.Shiny());
    
    return specular;
}

Color Light::Illuminate(const Shape* shape, const Ray& ray, GLfloat rayIntersectionT) {
    Vector intersection = ray.FindPoint(rayIntersectionT);
    Vector toLightDistance = _position - intersection;
    Vector toLight = toLightDistance.normalizedVector();
    
    Vector normal = shape->findNormalAtPoint(intersection);
//
//    Color color = _ambient * shape->Mat().Ambient();

    Color color = CalculateDiffuse(shape->Mat(), normal, toLight) +
                  CalculateSpecular(shape->Mat(), normal, toLight, ray.Direction());
    
    return color;
}
