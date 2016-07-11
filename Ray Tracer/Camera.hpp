//
//  Camera.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Vector.hpp"
#include "Scene.hpp"
#include "Common.h"

class Camera {
public:
    Camera();
    Camera(Vector position, Vector direction, GLfloat imagePlaneDist);
    
    void MoveTo(Vector position);
    void ChangeDirection(Vector position);
    void RenderScene(Scene scene);
    
private:
    Vector _position;
    Vector _direction;
    GLfloat _planeDist;
};

#endif /* Camera_hpp */
