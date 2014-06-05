//
//  main.cpp
//  xcodec++
//
//  Created by Johnny Lee on 6/1/14.
//  Copyright (c) 2014 ___4Dplus___. All rights reserved.
//

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void processKeys(unsigned char key, int xx, int yy) {
	switch (key) {
            
        case 27: // QUIT
            glutLeaveMainLoop();
	}
}
void initRendering()
{
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);//camera view
    glLoadIdentity(); // replace the current matrix with the identity matrix
    //Set the Orthogonal Projection Volume to the
    
    glOrtho(-256, 256, -256, 256, -256, 256);
    glViewport(0,0,10,20);
    
}
void drawScene()
{
    //----------------triangle begin----------------------
    
    glBegin(GL_TRIANGLES);
    //triangle 1
    glColor3f(0.5f, 0.0f, 0.8f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(100.0f, 0.0f);
	glVertex2f(0.0f, 100.0f);
    //triangle 2
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-100.0f, 0.0f);
    glVertex2f(0.0f, 100.0f);
    //triangle 3
    glColor3f(0.0f, 0.0f, 0.8f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-100.0f, 0.0f);
    glVertex2f(0.0f, -100.0f);
    //triangle 4
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(100.0f, 0.0f);
    glVertex2f(0.0f, -100.0f);
    
    glEnd();
    //----------------triangle end----------------------
    glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv);
    //Set your desired Windows Size
    glutInitWindowPosition (50, 100);  //set windows position
    glutInitWindowSize(512, 512);
    //OpenGL Display Mode //GLUT_3_3_CORE_PROFILE
    //glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    //The title of the Window
    glutCreateWindow("CG I - Assignment 1");
    //Rendering Function
    //-----------------------------------------
    initRendering(); //initialize basic rendering
    glutKeyboardFunc(processKeys);
    glutDisplayFunc(drawScene);//draw function
    
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        cout<<"glew init error\n";
    }
    printf("OpenGL vendor supported by this platform (%s): \n",
           glGetString(GL_VENDOR));
	printf("OpenGL renderer supported by this platform (%s): \n",
           glGetString(GL_RENDERER));
	printf("OpenGL version supported by this platform (%s): \n",
           glGetString(GL_VERSION));
    
    cout<<"Glew version"<<glewGetString(GLEW_VERSION)<<endl;
    cout<<"Glut version"<<glutGet(GLUT_VERSION)<<endl;
    //------------------------------------------------
    glutMainLoop();
    return 0;
}

