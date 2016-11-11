//
//  Core.hpp
//  OpenGL
//
//  Created by Joey Welvaadt on 31/10/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include <stdio.h>
#include "main.h"


class Core {
private:
public:
    bool Initialize();
    GLFWwindow *CreateWindow(int windowWidth, int windowHeight);
protected:
};

#endif /* Core_hpp */
