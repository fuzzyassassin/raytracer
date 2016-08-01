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
    v.SetX(1.0);
    EXPECT_NE(v, w);
}

TEST(DefaultConstructor, Default) {
    Vector v = Vector();
    EXPECT_EQ(v.X(), 0);
    EXPECT_EQ(v.Y(), 0);
    EXPECT_EQ(v.Z(), 0);
    EXPECT_EQ(v.Length(), 0);
}

TEST(Constructor, Zeroes) {
    Vector v = Vector(0, 0, 0);
    Vector w = Vector();
    EXPECT_EQ(v.Length(), 0);
    EXPECT_EQ(v, w);
}

TEST(Constructor, Arbitrary) {
    Vector v = Vector(0, 0, 1);
    EXPECT_EQ(v.Length(), 1);
}

TEST(Constructor, Ones) {
    Vector v = Vector(1, 1, 1);
    EXPECT_EQ(v.X(), 1);
    EXPECT_EQ(v.Y(), 1);
    EXPECT_EQ(v.Z(), 1);
}

TEST(Constructor, Copy) {
    Vector v = Vector(2, 2, 2);
    Vector w = Vector(v);
    EXPECT_EQ(v, w);
}

TEST(SetComponents, X) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.Length(), 0);
    v.SetX(3);
    EXPECT_EQ(v.X(), 3);
    EXPECT_EQ(v.Length(), 3);
}

TEST(SetComponents, Y) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.Length(), 0);
    v.SetY(3);
    EXPECT_EQ(v.Y(), 3);
    EXPECT_EQ(v.Length(), 3);
}

TEST(SetComponents, Z) {
    Vector v = Vector(0, 0, 0);
    EXPECT_EQ(v.Length(), 0);
    v.SetZ(3);
    EXPECT_EQ(v.Z(), 3);
    EXPECT_EQ(v.Length(), 3);
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
    EXPECT_FLOAT_EQ(v.Length(), l);
}

TEST(VectorFunctions, LengthWithZero) {
    Vector v = Vector(3, 4, 0);
    GLdouble l = 5.0f;
    EXPECT_FLOAT_EQ(v.Length(), l);
}

TEST(VectorFunctions, LengthZero) {
    Vector v = Vector(0, 0, 0);
    GLdouble l = 0.0f;
    EXPECT_FLOAT_EQ(v.Length(), l);
}

TEST(VectorFunctions, NormalizedVector) {
    Vector v = Vector(1, 2, 3);
    Vector vn = v.NormalizedVector();
    GLdouble length = v.Length();
    EXPECT_EQ(vn.X(), v.X()/length);
    EXPECT_EQ(vn.Y(), v.Y()/length);
    EXPECT_EQ(vn.Z(), v.Z()/length);
    EXPECT_FLOAT_EQ(vn.Length(), 1.0f);
}

TEST(VectorFunctions, NormalizedVectorZero) {
    Vector v = Vector(0, 0, 0);
    Vector vn = v.NormalizedVector();
    EXPECT_EQ(vn.X(), NAN);
    EXPECT_EQ(vn.Y(), NAN);
    EXPECT_EQ(vn.Z(), NAN);
    EXPECT_FLOAT_EQ(vn.Length(), NAN);
}

TEST(VectorFunctions, Normalization) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(v);
    GLdouble length = w.Length();
    v.Normalize();
    EXPECT_EQ(v.X(), w.X()/length);
    EXPECT_EQ(v.Y(), w.Y()/length);
    EXPECT_EQ(v.Z(), w.Z()/length);
    EXPECT_FLOAT_EQ(v.Length(), 1.0f);
}

TEST(VectorFunctions, NormalizationZero) {
    Vector v = Vector(0, 0, 0);
    Vector w = Vector(v);
    GLdouble length = w.Length();
    v.Normalize();
    EXPECT_EQ(v.X(), w.X()/length);
    EXPECT_EQ(v.Y(), w.Y()/length);
    EXPECT_EQ(v.Z(), w.Z()/length);
    EXPECT_FLOAT_EQ(v.Length(), 1.0f);
}

TEST(VectorFunctions, Projection) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(.5, .5, .5);
    Vector vPw = v.ProjectionOnto(w);
    Vector expected = Vector(2.0, 2.0, 2.0);
    EXPECT_EQ(vPw, expected);
}

TEST(VectorFunctions, DotProductZero) {
    Vector v = Vector(1, 0, 1);
    Vector w = Vector(0, 1, 0);
    EXPECT_FLOAT_EQ(v.Dot(w), 0);
}

TEST(VectorFunctions, DotProduct) {
    Vector v = Vector(1, 0, 1);
    Vector w = Vector(10, 2, -3);
    GLdouble expected = 7;
    EXPECT_FLOAT_EQ(v.Dot(w), expected);
}

TEST(VectorFunctions, DotProductSelf) {
    Vector v = Vector(2, 3, 4);
    GLdouble expected = 29;
    EXPECT_FLOAT_EQ(v.Dot(v), expected);
}

TEST(VectorFunctions, Cross) {
    Vector v = Vector(1, 2, 3);
    Vector w = Vector(5, 7, 1);
    Vector expected = Vector(-19, 14, -3);
    EXPECT_EQ(v.Cross(w), expected);
}

TEST(VectorFunctions, CrossOpposite) {
    Vector v = Vector(2, 3, 4);
    Vector expected = Vector();
    EXPECT_EQ(v.Cross(-v), expected);
}

TEST(VectorFunctions, ReflectedAcrossX) {
    Vector v = Vector(1, 1, 0);
    Vector axis = Vector(1, 0, 0);
    Vector result = Vector(1, -1, 0);
    EXPECT_EQ(v.ReflectedAcross(axis), result);
}
