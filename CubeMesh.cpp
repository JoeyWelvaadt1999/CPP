//
//  CubeMesh.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 08/11/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include "Mesh.hpp"

Mesh::Mesh(glm::vec3 center, float halfSideLength, int verticesLength) {
    _center = center;
    _verticesLength = verticesLength;
    _halfSideLength = halfSideLength;
}

void Mesh::CreateMesh() {
    float vertices [] = {
        //x,y,z
        
        -1.0f, -1.0f,
        1.0f, -1.0f,
        1.0f, 1.0f,
        -1.0f, 1.0f
        
        /*//front face
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        
        //back face
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        
        //left face
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        
        //right face
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        
        //bottom face
        
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        _center.x - _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y - _halfSideLength, _center.z - _halfSideLength,
        
        //top face
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,
        _center.x - _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z + _halfSideLength,
        _center.x + _halfSideLength, _center.y + _halfSideLength, _center.z - _halfSideLength,*/
    };
    
    _vertices = vertices;
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, _vertices);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

//float* Mesh::GetMesh() {
  //  return _vertices;
//}
