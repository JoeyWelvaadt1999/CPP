//
//  Camera.hpp
//  OpenGL
//
//  Created by Joey Welvaadt on 02/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "main.h"

class Camera {
public:
    GLfloat LookAt (glm::vec3 _transform, glm::vec3 _cameraPos);
};

#endif /* Camera_hpp */
