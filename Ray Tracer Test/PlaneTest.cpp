//
//  PlaneTest.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/31/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include <stdio.h>
#include "Ray.hpp"
#include "Plane.hpp"
#include "Vector.hpp"
#include "gtest/gtest.h"

TEST(PlaneRayIntersection, Parallel) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, 1, 0), Vector(1, 0, 0));
    GLdouble t = p.RayIntersection(r);
    GLdouble expected = -1.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(PlaneRayIntersection, Perpendicular) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, 1, 0), Vector(0, -1, 0));
    GLdouble t = p.RayIntersection(r);
    GLdouble expected = 1.0;
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(PlaneRayIntersection, Slant) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, 1, 0), Vector(-1, -1, -1));
    GLdouble t = p.RayIntersection(r);
    GLdouble expected = sqrt(3);
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(PlaneRayIntersection, SlantBehind) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, -1, 0), Vector(-1, 1, -1));
    GLdouble t = p.RayIntersection(r);
    GLdouble expected = sqrt(3);
    EXPECT_FLOAT_EQ(t, expected);
}

TEST(PlaneNormal, AbovePlane) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, 1, 0), Vector(-1, -1, -1));
    GLdouble t = p.RayIntersection(r);
    Vector point = r.FindPoint(t);
    EXPECT_EQ(p.FindNormalAtPoint(point), Vector(0, 1, 0));
}

TEST(PlaneNormal, BelowPlane) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, -1, 0), Vector(-1, 1, -1));
    GLdouble t = p.RayIntersection(r);
    Vector point = r.FindPoint(t);
    EXPECT_EQ(p.FindNormalAtPoint(point), Vector(0, -1, 0));
}

TEST(PlaneNormalRay, AbovePlane) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, 1, 0), Vector(-1, -1, -1));
    GLdouble t = p.RayIntersection(r);
    Vector point = r.FindPoint(t);
    EXPECT_EQ(p.FindNormalForIntersectingRay(r), Vector(0, 1, 0));
}

TEST(PlaneNormalRay, BelowPlane) {
    Plane p = Plane(Vector(), Vector(0, 1, 0));
    Ray r = Ray(Vector(0, -1, 0), Vector(1, 1, 1));
    GLdouble t = p.RayIntersection(r);
    Vector point = r.FindPoint(t);
    EXPECT_EQ(p.FindNormalForIntersectingRay(r), Vector(0, -1, 0));
}
