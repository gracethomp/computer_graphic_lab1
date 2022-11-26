#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

using namespace std;

float x1=0.0f, y2 = 0.0f;

void DrawGLScene();
void ReSizeGLScene(int Width, int Height);
void drawAnimal();
void move(int key, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //инициализируем библиотеку glut
    glutInitWindowSize (1500, 1000); //устанавливаем размеры окна
    glutCreateWindow ("Dog (or rabbit idk) is moving..."); //создаем окно и даем ему название

    glClearColor(0.79f, 0.55f, 0.82f, 1.0f); //задаем цвет фона

    glutDisplayFunc(DrawGLScene);
    glutReshapeFunc(ReSizeGLScene);
    glutSpecialFunc(move);
    glutIdleFunc(DrawGLScene);
    glutMainLoop();

    return 0;
}

GLvoid DrawGLScene(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(-1.5f + x1,0.0f + y2 ,-13.0f);
    glColor3ub(126.0f, 191.0f, 69.0f);
    drawAnimal();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3ub(0.0f, 0.0f, 0.0f);
    drawAnimal();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glFlush();
}


GLvoid ReSizeGLScene(int Width, int Height)
{
    glViewport(0,0,Width,Height); //задаем окно просмотра

    glMatrixMode(GL_PROJECTION); //
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawAnimal() {
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 0.0f, 1.0f);		// Top
        glVertex2f(0.0f,-1.0f);		// Bottom Left
        glVertex2f( 2.0f,-1.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 1.0f, 2.5f);		// Top
        glVertex2f( 0.0f, 1.5f);		// Bottom Left
        glVertex2f( 1.0f,1.5f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 3.0f, 0.0f);		// Top
        glVertex2f( 1.0f, 0.0f);		// Bottom Left
        glVertex2f( 3.0f,-2.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 4.0f, 1.0f);		// Top
        glVertex2f( 3.0f, 0.0f);		// Bottom Left
        glVertex2f( 4.0f,0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 3.0f,-1.0f);	    // Top
        glVertex2f( 3.0f,-3.0f);		// Bottom Left
        glVertex2f( 4.0f,-2.0f);			// Bottom Right
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
        glVertex2f(-1.0f, 1.5f);		// Top Left
        glVertex2f( 0.0f, 1.5f);		// Top Right
        glVertex2f( 0.0f,0.5f);		// Bottom Right
        glVertex2f(-1.0f,0.5f);		// Bottom Left
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
        glVertex2f(-0.5f,-1.0f);	    // Top Left
        glVertex2f( 1.0f,-1.0f);		// Top Right
        glVertex2f( 0.5f,-2.0f);		// Bottom Right
        glVertex2f(-1.0f,-2.0f);		// Bottom Left
    glEnd();
}

void move(int key, int x, int y)
{
    switch(key)
    {
        case 'a': {
            x1-= 1.0;
            break;
        }
        case 'd': {
            x1+= 1.0;
            break;
        }
        case 'w': {
            y2 += 1.0;
            break;
        }
        case 's': {
            y2 -= 1.0;
            break;
        }
    }
}
