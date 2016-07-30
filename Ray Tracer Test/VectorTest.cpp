//
//  VectorTest.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 7/30/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include "Vector.hpp"
#include "gtest/gtest.h"

TEST(DefaultConstructor, Default) {
    Vector v = Vector();
    EXPECT_EQ(v.x(), 0);
}
