//
//  Ray.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/7/16.
//
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>
#include "Vector.hpp"

class Ray {
public:
    Ray(Vector position, Vector direction);
    
    Vector FindPoint(GLdouble t) const;
    Vector Position() const;
    Vector Direction() const;
    
private:
    Vector position;
    Vector direction;
};

#endif /* Ray_hpp */
