//
//  main.cpp
//  OpenGL
//
//  Created by Joey Welvaadt on 26/10/16.
//  Copyright © 2016 Joey Welvaadt. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>


#include "main.h"
#include "Grid.hpp"
#include "Core.hpp"
#include "Input.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;
using namespace glm;

GLfloat rotationX = 0.0f;
GLboolean rotateXPos = false;
GLboolean rotateXNeg = false;

GLfloat rotationY = 0.0f;
GLboolean rotateYPos = false;
GLboolean rotateYNeg = false;

GLfloat posX = 0.0f;
GLboolean moveXPos = false;
GLboolean moveXNeg = false;

GLfloat posY = 0.0f;
GLboolean moveYPos = false;
GLboolean moveYNeg = false;

bool wireframe = false;

Grid grid(5);
Core core;
Camera cam;
Mesh m(glm::vec3(0,0,0), 0.5f, 4);


void RenderCube(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat sideLength);
void KeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods);


int main(int argc, const char * argv[]) {
    
    GLFWwindow *window;
    if(core.Initialize()) {
        window = core.CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    
    Input *i = new Input(window);
    i->KeyInput(KeyCallBack);
    
    
    
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;
    
    double mouseX, mouseY;
    
    
    while(!glfwWindowShouldClose(window))
    {
        glfwGetCursorPos(window, &mouseX, &mouseY);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glPushMatrix();
        
        
        
        if(rotateYPos) {
            rotationY += 1.0f;
        } else if (rotateYNeg) {
            rotationY -= 1.0f;
        }
        
        if(rotateXPos) {
            rotationX += 1.0f;
        } else if (rotateXNeg) {
            rotationX -= 1.0f;
        }
        
        if(moveYPos) {
            posY += 1.0f;
        } else if (moveYNeg) {
            posY -= 1.0f;
        }
        
        if(moveXPos) {
            posX += 1.0f;
        } else if (moveXNeg) {
            posX -= 1.0f;
        }
        
        
        glTranslatef(posX, 0, posY);
        
        
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        
        grid.DrawGrid(1000, glm::vec3(125, 125, 125), -10);
        
        m.CreateMesh();
        
        RenderCube(0, 0, 0, 1);
        RenderCube(0, 0, 10, 1);
        RenderCube(0, 0, -10, 1);
        
        glPopMatrix();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();

    return 0;
}

void KeyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_UP:
                rotateXNeg = false;
                rotateXPos = true;
                break;
            case GLFW_KEY_DOWN:
                rotateXNeg = true;
                rotateXPos = false;
                break;
            case GLFW_KEY_LEFT:
                rotateYNeg = true;
                rotateYPos = false;
                break;
            case GLFW_KEY_RIGHT:
                rotateYNeg = false;
                rotateYPos = true;
                break;
            case GLFW_KEY_W:
                moveYPos = true;
                moveYNeg = false;
                break;
            case GLFW_KEY_S:
                moveYPos = false;
                moveYNeg = true;
                break;
            case GLFW_KEY_A:
                moveXPos = false;
                moveXNeg = true;
                break;
            case GLFW_KEY_D:
                moveXPos = true;
                moveXNeg = false;
                break;
            case GLFW_KEY_R:
                wireframe = !wireframe;
                break;
           
            default:
                
                break;
        }
      
    } else {
        rotateXPos = false;
        rotateXNeg = false;
        rotateYNeg = false;
        rotateYPos = false;
        moveXPos = false;
        moveXNeg = false;
        moveYNeg = false;
        moveYPos = false;
    }
    
}


void RenderCube(GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat sideLength) {
    GLfloat halfLength = sideLength / 2;
    
    float colours[] = {
        255, 0, 0,
        255, 0, 0,
        255, 0, 0,
        255, 0, 0,
        
        0, 255, 0,
        0, 255, 0,
        0, 255, 0,
        0, 255, 0,
        
        0, 0, 255,
        0, 0, 255,
        0, 0, 255,
        0, 0, 255,
        
        255, 255, 0,
        255, 255, 0,
        255, 255, 0,
        255, 255, 0,
        
        0, 255, 255,
        0, 255, 255,
        0, 255, 255,
        0, 255, 255,
        
        255, 255, 255,
        255, 255, 255,
        255, 255, 255,
        255, 255, 255
    };
    
    float vertices[] = {
        //x,y,z
        
        //front face
        centerX - halfLength, centerY - halfLength, centerZ - halfLength,
        centerX - halfLength, centerY + halfLength, centerZ - halfLength,
        centerX + halfLength, centerY + halfLength, centerZ - halfLength,
        centerX + halfLength, centerY - halfLength, centerZ - halfLength,
        
        //back face
        centerX - halfLength, centerY - halfLength, centerZ + halfLength,
        centerX - halfLength, centerY + halfLength, centerZ + halfLength,
        centerX + halfLength, centerY + halfLength, centerZ + halfLength,
        centerX + halfLength, centerY - halfLength, centerZ + halfLength,
        
        //left face
        centerX - halfLength, centerY - halfLength, centerZ - halfLength,
        centerX - halfLength, centerY + halfLength, centerZ - halfLength,
        centerX - halfLength, centerY + halfLength, centerZ + halfLength,
        centerX - halfLength, centerY - halfLength, centerZ + halfLength,
        
        //right face
        centerX + halfLength, centerY - halfLength, centerZ - halfLength,
        centerX + halfLength, centerY + halfLength, centerZ - halfLength,
        centerX + halfLength, centerY + halfLength, centerZ + halfLength,
        centerX + halfLength, centerY - halfLength, centerZ + halfLength,
        
        //bottom face
        
        centerX - halfLength, centerY - halfLength, centerZ - halfLength,
        centerX - halfLength, centerY - halfLength, centerZ + halfLength,
        centerX + halfLength, centerY - halfLength, centerZ + halfLength,
        centerX + halfLength, centerY - halfLength, centerZ - halfLength,
        
        //top face
        centerX - halfLength, centerY + halfLength, centerZ - halfLength,
        centerX - halfLength, centerY + halfLength, centerZ + halfLength,
        centerX + halfLength, centerY + halfLength, centerZ + halfLength,
        centerX + halfLength, centerY + halfLength, centerZ - halfLength,
    };
    
    
    if(wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
       glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colours);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    
}
