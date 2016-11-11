//
//  CubeMesh.hpp
//  OpenGL
//
//  Created by Joey Welvaadt on 08/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "main.h"

class Mesh {
    
public:
    Mesh(glm::vec3 center, float halfSideLength, int verticesLength);
    //float* GetMesh();
    float *_vertices;
    void CreateMesh();
private:
    
    glm::vec3 _center;
    //float *_vertices;
    float *_rgba;
    float _halfSideLength;
    int _verticesLength;
protected:
};

#endif /* Mesh_hpp */
