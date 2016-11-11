//
//  Grid.hpp
//  OpenGL
//
//  Created by Joey Welvaadt on 31/10/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include "main.h"

class Grid {
public:
    Grid(int lineSpacing);
    void DrawGrid(int halfGridSize, glm::vec3 color, GLfloat height);
private:
    void DrawLine (glm::vec3 start, glm::vec3 end);
    int _lineSpacing;
protected:
};

#endif /* Grid_hpp */
