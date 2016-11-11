//
//  Input.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 01/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include "Input.hpp"



Input::Input(GLFWwindow *window) {
    _window = window;
}

void Input::KeyInput(GLFWkeyfun callback) {
    
    glfwSetKeyCallback(_window, callback);
}

void Input::MouseInput() {
    glEnable(GLFW_CURSOR);
}
