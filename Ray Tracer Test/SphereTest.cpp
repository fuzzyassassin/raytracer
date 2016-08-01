//
//  SphereTest.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/30/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "Sphere.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "gtest/gtest.h"

TEST(RayIntersection, AlongAxis) {
    Sphere s = Sphere(Vector(), 2);
    Ray r = Ray(Vector(3, 0, 0), Vector(-1, 0, 0));
    GLdouble expectedT = 1.0f;
    EXPECT_FLOAT_EQ(s.RayIntersection(r), expectedT);
}

TEST(RayIntersection, OneSolutionAxisAligned) {
    Sphere s = Sphere(Vector(), 2);
    Ray r = Ray(Vector(3, 2, 0), Vector(-1, 0, 0));
    GLdouble expectedT = 3.0f;
    EXPECT_FLOAT_EQ(s.RayIntersection(r), expectedT);
}

TEST(RayIntersection, OneSolutionNoAlignment) {
    Sphere s = Sphere(Vector(), 2);
    GLdouble intCoord= (2.0/sqrtf(3));
    Ray r = Ray(Vector(-intCoord - 1, intCoord - 1, -intCoord - 1), Vector(1, 1, 1));
    GLdouble expectedT = sqrtf(3);
    EXPECT_FLOAT_EQ(s.RayIntersection(r), expectedT);
}

TEST(RayIntersection, NoSolution) {
    Sphere s = Sphere(Vector(), 2);
    Ray r = Ray(Vector(3, 2.01, 0), Vector(-1, 0, 0));
    GLdouble expectedT = -1.0f;
    EXPECT_FLOAT_EQ(s.RayIntersection(r), expectedT);
}

TEST(FindNormal, HeadOnX) {
    Sphere s = Sphere(Vector(), 2);
    Ray r = Ray(Vector(3, 0, 0), Vector(-1, 0, 0));
    GLdouble t = s.RayIntersection(r);
    Vector result = r.FindPoint(t);
    Vector expectedNormal = Vector(1, 0, 0);
    EXPECT_EQ(s.FindNormalAtPoint(result), expectedNormal);
}

TEST(FindNormal, OffCenter) {
    Sphere s = Sphere(Vector(), 2);
    Ray r = Ray(Vector(3, 1, 0), Vector(-1, 0, 0));
    GLdouble t = s.RayIntersection(r);
    Vector point = r.FindPoint(t);
    EXPECT_EQ(s.FindNormalAtPoint(point), point.NormalizedVector());
}

TEST(FindNormal, OffCenterShifted) {
    Sphere s = Sphere(Vector(1, 0, 0), 2);
    Ray r = Ray(Vector(4, 1, 0), Vector(-1, 0, 0));
    GLdouble t = s.RayIntersection(r);
    Vector point = r.FindPoint(t);
    Vector result = s.FindNormalAtPoint(point);
    Vector expected = point - Vector(1, 0, 0);
    EXPECT_EQ(result.NormalizedVector(), expected.NormalizedVector());
}
