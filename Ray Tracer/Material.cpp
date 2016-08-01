//
//  Material.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include "Material.hpp"

Material::Material() {
    ambient = Color(64, 178, 64, 255);
    diffuse = Color(64, 178, 64, 255);
    specular = Color(64, 178, 64, 255);
    shiny = 3.0f;
}

Material::Material(Color ambient, Color diffuse, Color specular, GLdouble shiny) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shiny = shiny;
}

Color Material::Ambient() const {
    return ambient;
}
Color Material::Diffuse() const {
    return diffuse;
}
Color Material::Specular() const {
    return specular;
}
GLdouble Material::Shiny() const {
    return shiny;
}
