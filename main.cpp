#define GL_SILENCE_DEPRECATION


#include <OpenGL/gl.h>		// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>		// Header File For The GLu32 Library
#include <GLUT/glut.h>      // Header File For The GLut Library
#include <iostream>

using namespace std;

float x1=0.0f,y1=0.0f;

GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid ReSizeGLScene(int Width, int Height);
void drawAnimal();

void Go(int key, int x, int y)
{
    switch(key)
    {
        case 'a':
            x1-=1.0;
            break;
        case 'd':
            x1+=1.0;
            break;
        case 'w':
            y1+=0.0;
            break;
        case 's':
            y1-=0.0;
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000);
    glutCreateWindow (argv[0]);

    InitGL();
    glutDisplayFunc(DrawGLScene);	// tells GLUT that to use the DrawGLScene function when we want the scene drawn
    glutReshapeFunc(ReSizeGLScene);
    glutSpecialFunc(Go);
    glutIdleFunc(DrawGLScene);
    glutMainLoop();	// starts the program. Once called, program only returns to main() when quitting

    return 0;
}



// All the drawing code. Anything to be displayed on the screen should go in here.
GLvoid DrawGLScene(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();						// Reset the view

    glTranslatef(-1.5f + x1,0.0f + y1,-13.0f);			// Move left 1.5 units, and in to the screen 6.0 units
    glColor3ub(126.0f, 191.0f, 69.0f);
    drawAnimal();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3ub(0.0f, 0.0f, 0.0f);
    drawAnimal();
    glColor3ub(126.0f, 191.0f, 69.0f);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glFlush();
}



// Perform the setup for OpenGL: colour for clearing the screen, turning on the depth buffer,
// enable smooth shading, etc. This routine is not called until the OpenGL window has been created.
// Note: this function returns a value, but we'll ignore it for now
GLvoid InitGL(GLvoid)
{
    glShadeModel(GL_SMOOTH);	// Enable Smooth Shading (blends colours across a polygon/smoothed lighting
    glClearColor(0.79f, 0.55f, 0.82f, 1.0f);	// Green Background (RGBA; 0.0f = darkest, 1.0f = brightest)


    // Set-up the depth buffer
    glClearDepth(1.0f);		// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);	// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);		// The Type Of Depth Testing To Do

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

}



// - Resize the OpenGL scene each time the window has been resized.
// - This will be called at least once when the program is first run in order to set-up the perspective view.
// - The OpenGL scene will be resized based on the width and height of the window it's being displayed within.
GLvoid ReSizeGLScene(int Width, int Height)
{
    glViewport(0,0,Width,Height);	// Reset the current viewport.

    // The following lines set-up the screen for perspective view (things in the distance are smaller).
    // The perspective is calculated with a 45 degree viewing angle based on the window's width/height
    // 0.f, 100.0f are the starting and ending points for how deep we can draw in to the screen
    glMatrixMode(GL_PROJECTION);	// Select The Projection Matrix
    glLoadIdentity();				// Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);		// Select The Modelview Matrix
    glLoadIdentity();			// Reset The Modelview Matrix
}

void drawAnimal() {
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
    glVertex3f( 0.0f, 1.0f, 0.0f);		// Top
    glVertex3f(0.0f,-1.0f, 0.0f);		// Bottom Left
    glVertex3f( 2.0f,-1.0f, 0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
    glVertex3f( 1.0f, 2.5f, 0.0f);		// Top
    glVertex3f( 0.0f, 1.5f, 0.0f);		// Bottom Left
    glVertex3f( 1.0f,1.5f, 0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
    glVertex3f( 3.0f, 0.0f, 0.0f);		// Top
    glVertex3f( 1.0f, 0.0f, 0.0f);		// Bottom Left
    glVertex3f( 3.0f,-2.0f, 0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
    glVertex3f( 4.0f, 1.0f, 0.0f);		// Top
    glVertex3f( 3.0f, 0.0f, 0.0f);		// Bottom Left
    glVertex3f( 4.0f,0.0f, 0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
    glVertex3f( 3.0f,-1.0f, 0.0f);	    // Top
    glVertex3f( 3.0f,-3.0f, 0.0f);		// Bottom Left
    glVertex3f( 4.0f,-2.0f, 0.0f);			// Bottom Right
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
    glVertex3f(-1.0f, 1.5f, 0.0f);		// Top Left
    glVertex3f( 0.0f, 1.5f, 0.0f);		// Top Right
    glVertex3f( 0.0f,0.5f, 0.0f);		// Bottom Right
    glVertex3f(-1.0f,0.5f, 0.0f);		// Bottom Left
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
    glVertex3f(-0.5f,-1.0f, 0.0f);	    // Top Left
    glVertex3f( 1.0f,-1.0f, 0.0f);		// Top Right
    glVertex3f( 0.5f,-2.0f, 0.0f);		// Bottom Right
    glVertex3f(-1.0f,-2.0f, 0.0f);		// Bottom Left
    glEnd();
}