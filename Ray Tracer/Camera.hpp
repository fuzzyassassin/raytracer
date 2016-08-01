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
#include "Color.hpp"

class Camera {
public:
    Camera(Scene scene);
    Camera(Scene scene, GLdouble imagePlaneDist, GLdouble fov);
    Camera(const Camera &c);
    
    Color ShootRay(int x, int y, int width, int height);
    Color RayTrace(const Ray& ray, int remainingBounces);
    
private:
    Vector _position;
    GLdouble _planeDist;
    GLdouble _fov;
    GLdouble _imageWidth;
    Scene _scene;
};

#endif /* Camera_hpp */
