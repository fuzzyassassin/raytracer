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

class Light {
public:
    Light(Vector position, Color ambient, Color diffuse, Color specular);
    
    Vector Position();
    Color Ambient();
    Color Diffuse();
    Color Specular();
};

#endif /* Light_hpp */
