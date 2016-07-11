//
//  RunRaytracer.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/18/16.
//
//

#include <stdio.h>
#include "Common.h"
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

int main (int argc, char** argv) {
    int win;
    
    glutInit(&argc, argv);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(x, y); // might be y, x
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    win = glutCreateWindow("Raytracer");
    glutSetWindow(win);
    
    Renderer renderer = init(width, height);
    
    glutDisplayFunc(renderer.Render());
    glutKeyboardFunc(/* pass key handler */);
    glutMainLoop();
    return 0;
}

Renderer init(int w, int h) {
    /* OpenGL setup */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    // initCamera
        // sets plane distance, camera position, and fov
    Camera cam();
    
    // initScene
        // old just creates objects and fills the shapes array
    Scene scene();
    
    // initCanvas
        // allocates memory to store pixel data
    Renderer renderer(w, h, cam, scene);
    
    return renderer;    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // drawScene();
    // flushCanvas();
        // glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        // glRasterPos3f(0.0,0.0,0.0);
        // glDrawPixels(width,height,GL_RGB,GL_UNSIGNED_BYTE,canvas);
    glFlush();
}