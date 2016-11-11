//
//  Camera.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 02/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include "Camera.hpp"

GLfloat Camera::LookAt(glm::vec3 _transform, glm::vec3 _cameraPos) {
    //GLfloat disX = _transform.x - _cameraPos.x;
    GLfloat disY = _transform.y - _cameraPos.y;
    GLfloat disZ = _transform.z - _cameraPos.z;
    
    GLfloat angleX;
    GLfloat angleY;
    
    angleX = atanf(disY / disZ);
    
    return angleX * (180 / M_PI);
}
