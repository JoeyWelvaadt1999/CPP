//
//  Input.hpp
//  OpenGL
//
//  Created by Joey Welvaadt on 01/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include "main.h"

class Input {
public:
    Input(GLFWwindow *window);
    void KeyInput(GLFWkeyfun callback);
    void MouseInput();
private:
    GLFWwindow *_window;
protected:
};

#endif /* Input_hpp */
