//
//  Color.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/14/16.
//
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include "Common.h"

class Color {
    
public:
    Color();
    Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    
    GLfloat r();
    GLfloat g();
    GLfloat b();
    GLfloat a();
    
private:
    GLfloat components[4];
};

#endif /* Color_hpp */
