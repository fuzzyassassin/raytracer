//
//  VectorTest.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/30/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include "Vector.hpp"
#include "gtest/gtest.h"
#include <math.h>

TEST(EqualityOperator, Defaults) {
    Vector v = Vector();
    Vector w = Vector();
    EXPECT_EQ(v, w);
}

TEST(EqualityOperator, Different) {
    Vector v = Vector();
    Vector w = Vector();
    EXPECT_EQ(v, w);
    v.setX(1.0);
    EXPECT_NE(v, w);
}

TEST(DefaultConstructor, Default) {
    Vector v = Vector();
    EXPECT_EQ(v.x(), 0);
    EXPECT_EQ(v.y(), 0);
    EXPECT_EQ(v.z(), 0);
    EXPECT_EQ(v.length(), 0);
}

TEST(Constructor, Zeroes) {
    Vector v = Vector(0, 0, 0);
    Vector w = Vector();
    EXPECT_EQ(v.length(), 0);
    EXPECT_EQ(v, w);
}

TEST(Constructor, Arbitrary) {
    Vector v = Vector(0, 0, 1);
    EXPECT_EQ(v.length(), 1);
}

TEST(Constructor, Ones) {
    Vector v = Vector(1, 1, 1);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), 1);
    EXPECT_EQ(v.z(), 1);
}

TEST(Constructor, Copy) {
    Vector v = Vector(2, 2, 2);
    Vector w = Vector(v);
    EXPECT_EQ(v, w);
}

TEST(SetComponents, X) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.length(), 0);
    v.setX(3);
    EXPECT_EQ(v.x(), 3);
    EXPECT_EQ(v.length(), 3);
}

TEST(SetComponents, Y) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.length(), 0);
    v.setY(3);
    EXPECT_EQ(v.y(), 3);
    EXPECT_EQ(v.length(), 3);
}

TEST(SetComponents, Z) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.length(), 0);
    v.setZ(3);
    EXPECT_EQ(v.z(), 3);
    EXPECT_EQ(v.length(), 3);
}

TEST(Operators, Negative) {
    Vector v = Vector(3, 2, -1);
    Vector nv = Vector(-3, -2, 1);
    EXPECT_EQ(-v, nv);
}

TEST(Operators, NegativeZero) {
    Vector v = Vector(0, 0, 0);
    Vector nv = Vector(0, 0, 0);
    EXPECT_EQ(-v, nv);
}

TEST(Operators, Addition) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(2, 4, 6);
    EXPECT_EQ(v + v, w);
}

TEST(Operators, Subtraction) {
    Vector v = Vector(1, 2, 3);
    EXPECT_EQ(v - v, Vector());
}

//TEST(Operators, Multiplication) {
//    Vector u = Vector(1, 2, 3);
//    Vector w = Vector(2, 4, 6);
//    EXPECT_EQ(2 * u, w);
//}

TEST(Operators, SymmetricMultiplication) {
    Vector u = Vector(1, 2, 3);
    Vector w = Vector(2, 4, 6);
    EXPECT_EQ(u * 2, w);
}

TEST(Operators, Division) {
    Vector w = Vector(4, 6, 8);
    Vector u = Vector(2, 3, 4);
    EXPECT_EQ(w / 2, u);
}

TEST(Operators, PlusEquals) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(4, 5, 6);
    v += w;
    Vector vw = Vector(5, 7, 9);
    EXPECT_EQ(v, vw);
}

TEST(Operators, MinusEquals) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(4, 5, 6);
    v -= w;
    Vector vw = Vector(-3, -3, -3);
    EXPECT_EQ(v, vw);
}

TEST(Operators, TimesEquals) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(2, 4, 6);
    v *= 2;
    EXPECT_EQ(v, w);
}

TEST(Operators, DivideEquals) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(2, 4, 6);
    w /= 2;
    EXPECT_EQ(w, v);
}

TEST(VectorFunctions, Length) {
    Vector v = Vector(1, 2, 3);
    GLdouble l = sqrtf(14);
    EXPECT_FLOAT_EQ(v.length(), l);
}

TEST(VectorFunctions, LengthWithZero) {
    Vector v = Vector(3, 4, 0);
    GLdouble l = 5.0f;
    EXPECT_FLOAT_EQ(v.length(), l);
}

TEST(VectorFunctions, LengthZero) {
    Vector v = Vector(0, 0, 0);
    GLdouble l = 0.0f;
    EXPECT_FLOAT_EQ(v.length(), l);
}

TEST(VectorFunctions, NormalizedVector) {
    Vector v = Vector(1, 2, 3);
    Vector vn = v.normalizedVector();
    GLdouble length = v.length();
    EXPECT_EQ(vn.x(), v.x()/length);
    EXPECT_EQ(vn.y(), v.y()/length);
    EXPECT_EQ(vn.z(), v.z()/length);
    EXPECT_FLOAT_EQ(vn.length(), 1.0f);
}

TEST(VectorFunctions, NormalizedVectorZero) {
    Vector v = Vector(0, 0, 0);
    Vector vn = v.normalizedVector();
    EXPECT_EQ(vn.x(), NAN);
    EXPECT_EQ(vn.y(), NAN);
    EXPECT_EQ(vn.z(), NAN);
    EXPECT_FLOAT_EQ(vn.length(), NAN);
}

TEST(VectorFunctions, Normalization) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(v);
    GLdouble length = w.length();
    v.normalize();
    EXPECT_EQ(v.x(), w.x()/length);
    EXPECT_EQ(v.y(), w.y()/length);
    EXPECT_EQ(v.z(), w.z()/length);
    EXPECT_FLOAT_EQ(v.length(), 1.0f);
}

TEST(VectorFunctions, NormalizationZero) {
    Vector v = Vector(0, 0, 0);
    Vector w = Vector(v);
    GLdouble length = w.length();
    v.normalize();
    EXPECT_EQ(v.x(), w.x()/length);
    EXPECT_EQ(v.y(), w.y()/length);
    EXPECT_EQ(v.z(), w.z()/length);
    EXPECT_FLOAT_EQ(v.length(), 1.0f);
}

TEST(VectorFunctions, Projection) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(.5, .5, .5);
    Vector vPw = v.projectionOnto(w);
    Vector expected = Vector(2.0, 2.0, 2.0);
    EXPECT_EQ(vPw, expected);
}

TEST(VectorFunctions, DotProductZero) {
    Vector v = Vector(1, 0, 1);
    Vector w = Vector(0, 1, 0);
    EXPECT_FLOAT_EQ(v.dot(w), 0);
}

TEST(VectorFunctions, DotProduct) {
    Vector v = Vector(1, 0, 1);
    Vector w = Vector(10, 2, -3);
    GLdouble expected = 7;
    EXPECT_FLOAT_EQ(v.dot(w), expected);
}

TEST(VectorFunctions, DotProductSelf) {
    Vector v = Vector(2, 3, 4);
    GLdouble expected = 29;
    EXPECT_FLOAT_EQ(v.dot(v), expected);
}

TEST(VectorFunctions, Cross) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(5, 7, 1);
    Vector expected = Vector(-19, 14, -3);
    EXPECT_EQ(v.cross(w), expected);
}

TEST(VectorFunctions, CrossOpposite) {
    Vector v = Vector(2, 3, 4);
    Vector expected = Vector();
    EXPECT_EQ(v.cross(-v), expected);
}

TEST(VectorFunctions, ReflectedAcrossX) {
    Vector v = Vector(1, 1, 0);
    Vector axis = Vector(1, 0, 0);
    Vector result = Vector(1, -1, 0);
    EXPECT_EQ(v.ReflectedAcross(axis), result);
}
