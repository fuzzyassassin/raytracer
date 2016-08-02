//
//  main.cpp
//  Ray Tracer
//
//  Created by Kurt Bixby on 6/25/16.
//  Copyright © 2016 Fuzzy Apps. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Common.h"
#include "Renderer.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include "Plane.hpp"
#include "InputHandlerWrapper.hpp"

void openGlSetup() {
    /* OpenGL setup */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

Renderer init(int w, int h) {
    // initScene
    // old just creates objects and fills the shapes array
    Scene scene;
    
    Material sphereMat = Material(Color(50, 192, 128, 255), Color(50, 192, 128, 255), Color(50, 192, 128, 255), 2.0f);
    Sphere* circle = new Sphere(Vector(0, 0, -75), 5, sphereMat);
    Sphere* second = new Sphere(Vector(15, 10, -60), 6);
    Plane* plane = new Plane(Vector(0, -5, 0), Vector(0, -1, 0));
    
    scene.AddShape(circle);
    scene.AddShape(second);
    scene.AddShape(plane);
    scene.AddLight(Light(Vector(-10000, 3000, 1000), Color(255,0,0,1), Color(0,255,0,1), Color(0,0,255,1)));
    
    // initCamera
    // sets plane distance, camera position, and fov
    Camera cam(scene);
    
    // initCanvas
    // allocates memory to store pixel data
    Renderer renderer(w, h, cam);
    renderer.MakeStatic();
    
    return renderer;
}

void Triangle() {
    glBegin (GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.75);
    glVertex3f(0.9, 0.9, 0.0);
    glVertex3f(0.3, 0.5, 0.0);
    glVertex3f(0.9, 0.1, 0.0);
    glEnd();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Renderer::currentInstance->UpdateFramebufferSize(width, height);
}

int main(int argc, char * argv[]) {
    int width = 500;
    int height = 400;
    int x = 100;
    int y = 100;
    char title[] = "Ray Tracer";
    
    // glfw setup
//    glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    
    // glfw window creation
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    // glfw window setup
    glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    openGlSetup();
    
    // renderer setup
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    Renderer renderer = init(framebufferWidth, framebufferWidth);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        renderer.Render();
        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}
