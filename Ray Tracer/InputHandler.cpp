//
//  InputHandler.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include "InputHandler.hpp"

void InputHandler::HandleInput(unsigned char ch, int x, int y){
    switch(ch) {
        case 'l':
//            incrNumLights();
            break;
        case 'k':
//            decrNumLights();
            break;
        case 's':
//            incrNumShapes();
            break;
        case 'd':
//            decrNumShapes();
            break;
        case 'r':
//            toggleRecursion();
            break;
        case 'a':
//            toggleAA();
            break;
        default:
            /* Unrecognized keypress */
            return;
    }
};