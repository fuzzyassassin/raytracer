//
//  Light.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
#include "Color.hpp"
#include "Vector.hpp"
#include "Shape.hpp"
#include "Ray.hpp"

class Light {
public:
    Light();
    Light(Vector position, Color ambient, Color diffuse, Color specular);
    
    Vector Position() const;
    Color Ambient() const;
    Color Diffuse() const;
    Color Specular() const;
    
    Color CalculateAmbient(const Material& mat) const;
    Color CalculateDiffuse(const Material& mat, const Vector& normal, const Vector& toLight) const;
    Color CalculateSpecular(const Material& mat, const Vector& normal, const Vector& toLight, const Vector& incoming) const;
    Color Illuminate(const Shape* shape, const Ray& incoming, const Vector& point) const;
    
private:
    Vector _position;
    Color _ambient;
    Color _diffuse;
    Color _specular;
};

#endif /* Light_hpp */
