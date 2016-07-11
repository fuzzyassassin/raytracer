//
//  Renderer.cpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/25/16.
//
//

#include "Renderer.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Common.h"

Renderer* Renderer::currentInstance;

Renderer::Renderer(int w, int h, Camera c, Scene s) {
    UpdateFramebufferSize(w, h);
    
    scene = s;
    cam = c;
}

Renderer::~Renderer() {
    free(canvas);
}
    
void Renderer::Render() {
    Draw();
}

void Renderer::MakeStatic() {
    currentInstance = this;
}

void Renderer::Draw() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos3f(0.0,0.0,0.0);
    glDrawPixels(width,height,GL_RGB,GL_UNSIGNED_BYTE,canvas);
}

void Renderer::UpdateFramebufferSize(int w, int h) {
    InitializeCanvas(w, h);
    width = w;
    height = h;
}

void Renderer::InitializeCanvas(int w, int h) {
    if (canvas == nullptr) {
        free(canvas);
    }
    canvas = (GLubyte*) malloc(w*h*3*sizeof(GLubyte));
    /* clear it */
    for (int i=0; i<w*h*3; i++) {
        canvas[i]=0xF0;
    }
}
