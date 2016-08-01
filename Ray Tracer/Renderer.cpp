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

Renderer::Renderer(int w, int h, Camera c) : _cam(c) {
    UpdateFramebufferSize(w, h);
}

Renderer::~Renderer() {
    free(_canvas);
}
    
void Renderer::Render() {
    Draw();
}

void Renderer::MakeStatic() {
    currentInstance = this;
}

void Renderer::Draw() {
    
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            Color pixel = _cam.ShootRay(x, y, _width, _height);
            pixel.Clamp();
            WriteColor(pixel, x, y);
        }
    }
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos3f(0.0,0.0,0.0);
    glDrawPixels(_width,_height,GL_RGB,GL_UNSIGNED_BYTE,_canvas);
}

void Renderer::UpdateFramebufferSize(int w, int h) {
    InitializeCanvas(w, h);
    _width = w;
    _height = h;
}

void Renderer::WriteColor(Color& pixel, int x, int y) {
    if ((x < 0) || (x >= _width) || (y < 0) || (y >= _height)) return;
    _canvas[3*_width*(y)+3*(x)+RED] = (char)(pixel.R() * 255);
    _canvas[3*_width*(y)+3*(x)+GREEN] = (char)(pixel.G() * 255);
    _canvas[3*_width*(y)+3*(x)+BLUE] = (char)(pixel.B() * 255);
    
}

void Renderer::InitializeCanvas(int w, int h) {
    if (_canvas == nullptr) {
        free(_canvas);
    }
    _canvas = (GLubyte*) malloc(w*h*3*sizeof(GLubyte));
    /* clear it */
    for (int i=0; i<w*h*3; i++) {
        _canvas[i]=0xF0;
    }
}
