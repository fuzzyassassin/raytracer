//
//  Scene.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include "Shape.hpp"

class Scene {
public:
    Scene();
    int AddShape(Shape& shape);
    void RemoveShape(int id);
};

#endif /* Scene_hpp */
