//
//  Camera.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include <cmath>
#include <iterator>
#include <vector>
#include "Camera.hpp"
#include "Ray.hpp"

#define _USE_MATH_DEFINES
#define MAX_BOUNCES 4

Camera::Camera(Scene scene) {
    _position = Vector(0, 0, 0);
    _planeDist = 1.0;
    _fov = M_PI/6;
    _imageWidth = 2 * _planeDist * std::tan(_fov/2);
    _scene = scene;
}

Camera::Camera(Scene scene, GLdouble imagePlaneDist, GLdouble fov) {
    _planeDist = imagePlaneDist;
    _fov = fov;
    _imageWidth = 2 * _planeDist * std::tan(_fov/2);
    _scene = scene;
}

Camera::Camera(const Camera &c) {
    _position = c._position;
    _planeDist = c._planeDist;
    _fov = c._fov;
    _imageWidth = c._imageWidth;
    _scene = c._scene;
}

Color Camera::ShootRay(int x, int y, int width, int height) {
    // Calculate world location of pixel
    
    Vector location = Vector((x - (width/2)) * _imageWidth/width, (y - (height/2))* _imageWidth/width, -_planeDist);
    
    Vector direction = (location - _position);
    
    Ray ray = Ray(_position, direction);
    return RayTrace(ray, 0);
}

Color Camera::RayTrace(const Ray& ray, int bounces) {
    if (bounces > MAX_BOUNCES) {
        return Color(0, 0, 0, 0);
    }
    
    const Shape* shape = _scene.IntersectingShape(ray);
    if (shape == nullptr) {
        return Color(0, 0, 0, 0);
    }
    
    GLdouble rayIntersectionT = shape->RayIntersection(ray);
    Vector intersectionPoint = ray.FindPoint(rayIntersectionT);
    Vector intersectionNormal = shape->FindNormalAtPoint(intersectionPoint);
    Vector reflectedVector = (-ray.Direction()).ReflectedAcross(intersectionNormal);
    
    Ray reflected = Ray(intersectionPoint, reflectedVector);
    
    Color reflectedColor = RayTrace(reflected, bounces + 1);
    
    Color phongColor = Color(0, 0, 0, 1);
    
    // Abstract this iterator at some point
    const std::vector<Light> lights = _scene.Lights();
    for (std::vector<Light>::const_iterator it = lights.begin(); it != lights.end(); ++it) {
        Light curLight = *it;
        // Get point of intersection
        // Pass point of intersection and material
        phongColor += curLight.CalculateAmbient(shape->Mat());
        
        Vector intersection = ray.FindPoint(rayIntersectionT);
        Ray toLight = Ray(intersection, curLight.Position() - intersection);
        
        // Go to the next light if there's an object between the intersection and the light
        if (_scene.IntersectingShape(toLight) != nullptr) {
            continue;
        }
        
        phongColor += curLight.Illuminate(shape, -ray.Direction(), intersection);
        
    }
    
    Material mat = shape->Mat();
    Color result = mat.Specular() * reflectedColor + phongColor;
    
    return result;
}
