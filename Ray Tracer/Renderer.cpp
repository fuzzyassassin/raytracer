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
#include "Color.hpp"

Renderer* Renderer::currentInstance;

Renderer::Renderer(int w, int h, Camera c) : cam(c) {
    UpdateFramebufferSize(w, h);
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
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color pixel = cam.ShootRay(x, y, width, height);
            WriteColor(pixel, x, y);
        }
    }
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos3f(0.0,0.0,0.0);
    glDrawPixels(width,height,GL_RGB,GL_UNSIGNED_BYTE,canvas);
}

void Renderer::UpdateFramebufferSize(int w, int h) {
    InitializeCanvas(w, h);
    width = w;
    height = h;
}

void Renderer::WriteColor(Color& pixel, int x, int y) {
    if ((x < 0) || (x >= width) || (y < 0) || (y >= height)) return;
    canvas[3*width*(y)+3*(x)+RED] = (char)(pixel.r() * 255);
    canvas[3*width*(y)+3*(x)+GREEN] = (char)(pixel.g() * 255);
    canvas[3*width*(y)+3*(x)+BLUE] = (char)(pixel.b() * 255);
    
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
