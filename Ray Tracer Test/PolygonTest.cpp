//
//  PolygonTest.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 8/1/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include <vector>
#include <stdio.h>
#include "Ray.hpp"
#include "Plane.hpp"
#include "Vector.hpp"
#include "Polygon.hpp"
#include "gtest/gtest.h"

TEST(RayIntersection, HeadOnTriangle) {
    Plane p = Plane(Vector(), Vector(0, 0, 1));
    std::vector<Vector> points = std::vector<Vector>();
    points.push_back(Vector(3, 0, 1));
    points.push_back(Vector(1, 5, -2));
    points.push_back(Vector(-4, 0, 5));
    Polygon tri = Polygon(p, points);
    Ray r = Ray(Vector(0, 1, 2), Vector(0, 0, -1));
    GLdouble t = tri.RayIntersection(r);
    GLdouble expected = 2.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(RayIntersection, MissTriangle) {
    Plane p = Plane(Vector(), Vector(0, 0, 1));
    std::vector<Vector> points = std::vector<Vector>();
    points.push_back(Vector(3, 0, 1));
    points.push_back(Vector(1, 5, -2));
    points.push_back(Vector(-4, 0, 5));
    Polygon tri = Polygon(p, points);
    Ray r = Ray(Vector(4, 1, 2), Vector(0, 0, -1));
    GLdouble t = tri.RayIntersection(r);
    GLdouble expected = -1.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(RayIntersection, SlantTriangle) {
    Plane p = Plane(Vector(), Vector(0, 1, 1));
    std::vector<Vector> points = std::vector<Vector>();
    points.push_back(Vector(3, 0, 1));
    points.push_back(Vector(1, 5, -2));
    points.push_back(Vector(-4, 0, 5));
    Polygon tri = Polygon(p, points);
    Ray r = Ray(Vector(0, 1, 2), Vector(0, 0, -1));
    GLdouble t = tri.RayIntersection(r);
    GLdouble expected = 3.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(RayIntersection, HeadOnQuad) {
    Plane p = Plane(Vector(), Vector(0, 0, 1));
    std::vector<Vector> points = std::vector<Vector>();
    points.push_back(Vector(3, 1, 1));
    points.push_back(Vector(1, 3, -2));
    points.push_back(Vector(-3, -1, 5));
    points.push_back(Vector(-1, -3, 0));
    Polygon quad = Polygon(p, points);
    Ray r = Ray(Vector(0, 1, 2), Vector(0, 0, -1));
    GLdouble t = quad.RayIntersection(r);
    GLdouble expected = 3.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(RayIntersection, MissQuad) {
    Plane p = Plane(Vector(), Vector(0, 0, 1));
    std::vector<Vector> points = std::vector<Vector>();
    points.push_back(Vector(3, 1, 1));
    points.push_back(Vector(1, 3, -2));
    points.push_back(Vector(-3, -1, 5));
    points.push_back(Vector(-1, -3, 0));
    Polygon quad = Polygon(p, points);
    Ray r = Ray(Vector(0, 4, 2), Vector(0, 0, -1));
    GLdouble t = quad.RayIntersection(r);
    GLdouble expected = -1.0;
    EXPECT_FLOAT_EQ(t, expected);
}
