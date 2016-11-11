//
//  Core.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 31/10/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include "Core.hpp"

bool Core::Initialize() {
    if(!glfwInit()) {
        fprintf(stderr, "GLFW failed initializing");
    }
    
    
    
    return true;
}

GLFWwindow *Core::CreateWindow(int windowWidth, int windowHeight) {
    GLFWwindow *window;
    window = glfwCreateWindow(windowWidth , windowHeight, "Raybon", nullptr, nullptr);
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if(window == nullptr) {
        fprintf(stderr, "failed to create window \n");
        glfwTerminate();
        return NULL;
    }
    
    glfwMakeContextCurrent(window);
    
    
    glViewport(0, 0, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1.0f,1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    return window;
}
