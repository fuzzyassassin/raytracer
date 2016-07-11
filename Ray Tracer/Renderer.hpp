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
    
    Renderer(int w, int h, Camera c, Scene s);
    ~Renderer();
    void Render();
    void Draw();
    void MakeStatic();
    void UpdateFramebufferSize(int w, int h);
    
private:
    Camera cam;
    Scene scene;
    GLubyte* canvas;
    int width;
    int height;
    
    void InitializeCanvas(int w, int h);
};

#endif /* Renderer_hpp */
