//
//  Grid.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 31/10/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include "Grid.hpp"

Grid::Grid (int lineSpacing) {
    _lineSpacing = lineSpacing;
}

void Grid::DrawLine (glm::vec3 start, glm::vec3 end)
{
    glBegin (GL_LINES);
    glVertex3f (start.x, start.y, start.z);
    glVertex3f (end.x, end.y, end.z);
    glEnd();
}

void Grid::DrawGrid(int halfGridSize, glm::vec3 color, GLfloat height)
{
    glColor3ub (color.x, color.y, color.z);
    
    for (float x = -halfGridSize; x <= halfGridSize; x += _lineSpacing) {
        if ((int) x % 100 == 0) glLineWidth (3.0);
        else if ((int) x % 50 == 0) glLineWidth (2.0);
        else glLineWidth (1.0);
        
        Grid::DrawLine(glm::vec3(-(float)halfGridSize, height, x), glm::vec3((float) halfGridSize, height, x));
    }
    
    for (float y = -halfGridSize; y <= halfGridSize; y += _lineSpacing) {
        if ((int) y % 100 == 0) glLineWidth (3.0);
        else if ((int) y % 50 == 0) glLineWidth (2.0);
        else glLineWidth (1.0);
        
        Grid::DrawLine(glm::vec3(y, height, -(float)halfGridSize), glm::vec3(y, height, (float) halfGridSize));
    }
}
