//
//  Polygon.hpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 8/1/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#include <stdio.h>
#include <vector>
#include "Ray.hpp"
#include "Shape.hpp"
#include "Plane.hpp"
#include "Vector.hpp"
#include "Material.hpp"

class Polygon : public Shape {
    
public:
    Polygon();
    Polygon(Plane plane, std::vector<Vector> points);
    Polygon(Plane plane, std::vector<Vector> points, Material mat);
    
    GLdouble RayIntersection(const Ray& r) const override;
    Vector FindNormalAtPoint(const Vector& v) const override;
    Vector FindNormalForIntersectingRay(const Ray& r) const override;
};

#endif /* Polygon_hpp */
