//
//  Material.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include "Material.hpp"

Material::Material() {
    _ambient = Color(64, 178, 64, 255);
    _diffuse = Color(64, 178, 64, 255);
    _specular = Color(64, 178, 64, 255);
    _shiny = 3.0f;
}

Material::Material(Color ambient, Color diffuse, Color specular, GLdouble shiny) {
    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
    _shiny = shiny;
}

Color Material::Ambient() const {
    return _ambient;
}
Color Material::Diffuse() const {
    return _diffuse;
}
Color Material::Specular() const {
    return _specular;
}
GLdouble Material::Shiny() const {
    return _shiny;
}
