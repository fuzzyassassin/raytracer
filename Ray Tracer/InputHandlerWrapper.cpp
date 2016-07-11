//
//  InputHandlerWrapper.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include "InputHandlerWrapper.hpp"
#include "Common.h"
#include "InputHandler.hpp"

InputHandlerWrapper::InputHandlerWrapper() {
    // Takes reference to state/modes object
    handler = InputHandler();
}

void InputHandlerWrapper::HandleInput(unsigned char ch, int x, int y) {
    
    /*
     Pass input and state reference into actual handler
     */
    
    handler.HandleInput(ch, x, y);
//    glutPostRedisplay();
}
