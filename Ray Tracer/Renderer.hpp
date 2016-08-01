//
//  Renderer.hpp
//  RaytracerXcode
//
//  Created by Kurt Bixby on 6/25/16.
//
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Common.h"

class Renderer {
public:
    static Renderer* currentInstance;
    
    Renderer(int w, int h, Camera c);
    ~Renderer();
    void Render();
    void Draw();
    void MakeStatic();
    void UpdateFramebufferSize(int w, int h);
    void WriteColor(Color& pixel, int x, int y);
    
private:
    Camera _cam;
    GLubyte* _canvas;
    int _width;
    int _height;
    
    void InitializeCanvas(int w, int h);
};

#endif /* Renderer_hpp */
