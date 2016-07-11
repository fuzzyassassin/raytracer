//
//  InputHandlerWrapper.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#ifndef InputHandlerWrapper_hpp
#define InputHandlerWrapper_hpp

#include <stdio.h>
#include "InputHandler.hpp"

class InputHandlerWrapper {
public:
    InputHandlerWrapper();
    
    void HandleInput(unsigned char ch, int x, int y);
    
private:
    InputHandler handler;
};

#endif /* InputHandlerWrapper_hpp */
