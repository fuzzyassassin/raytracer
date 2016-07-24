//
//  Material.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#include "Material.hpp"

Material::Material() {
    ambient = Color();
    diffuse = Color();
    specular = Color();
    shiny = 0.0f;
}

Material::Material(Color ambient, Color diffuse, Color specular, GLfloat shiny) {
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
GLfloat Material::Shiny() const {
    return shiny;
}
