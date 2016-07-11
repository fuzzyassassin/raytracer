//
//  Material.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include "Color.hpp"
#include "Common.h"

class Material {
public:
    Material();
    Material(Color ambient, Color diffuse, Color specular, GLfloat shiny);
    
    Color Ambient();
    Color Diffuse();
    Color Specular();
    GLfloat Shiny();
    
private:
    Color ambient;
    Color diffuse;
    Color specular;
    GLfloat shiny;
};

#endif /* Material_hpp */
