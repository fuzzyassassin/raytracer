//
//  Scene.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include "Scene.hpp"
#include "Shape.hpp"

Scene::~Scene() {
    
}

const std::vector<Light> Scene::Lights() const {
    return _lights;
}

void Scene::AddShape(const Shape* shape) {
    _shapes.push_back(shape);
}

void Scene::AddLight(const Light light) {
    _lights.push_back(light);
}

const Shape* Scene::IntersectingShape(const Ray& ray) {
    GLdouble minT = -1;
    int minShapeIndex = -1;
    for (int i = 0; i < _shapes.size(); i++) {
        const Shape* shape = _shapes[i];
        GLdouble t = shape->RayIntersection(ray);
        if (t <= 0) {
            continue;
        }
        if (minT == -1 || t < minT) {
            minT = t;
            minShapeIndex = i;
        }
    }
    
    const Shape* shape = minShapeIndex != -1 ? _shapes[minShapeIndex] : nullptr;
    return shape;
}
