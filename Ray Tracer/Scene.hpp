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
#include <vector>
#include "Shape.hpp"
#include "Ray.hpp"
#include "Light.hpp"

class Scene {
public:
    ~Scene();
    
    void AddShape(const Shape* shape);
    void AddLight(const Light light);
    
    const std::vector<Light> Lights() const;
    const Shape* IntersectingShape(const Ray& ray);
    
private:
    std::vector<Light> lights;
    
    // Replace this with custom data structure
    // Should be more time efficient
    std::vector<const Shape*> shapes;
};

#endif /* Scene_hpp */
