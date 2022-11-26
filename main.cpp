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
    glutMainLoop(); //стартует программу

    return 0;
}

void DrawGLScene(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT); //очищаем буффер цвета
    glLoadIdentity(); //сбрасываем все переносы/масштабирования и тд

    glTranslatef(0.0f + x1,0.0f + y2 ,-20); //сдвиг системы координат
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //режим рисования - заполнение фигуры
    glColor3ub(126.0f, 191.0f, 69.0f); //задаем цвет, которым будем рисовать
    drawAnimal();
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //устанавливаем режим рисования - линия
    glColor3ub(0.0f, 0.0f, 0.0f); //цвет линии
    drawAnimal();
    glFlush();
}
// - функция изменения размера сцены каждый раз когда окно меняет размер
// - она будет вызвана как минимум один раз когда программа впервые запустится
// - сцена опенгл будет менять размер основываясь на ширине и высоте окна
void ReSizeGLScene(int Width, int Height)
{
    glViewport(0,0,Width,Height); //сбрасываем текущее окно просмотра
    glMatrixMode(GL_PROJECTION); //команды относятся к проекту
    glLoadIdentity(); //сбрасываем текущую матрицу
    //рассчитывает соотношение сторон окна
    //fovy - угол видимости
    //aspect - соотношение сторон
    gluPerspective(50.0f,(float)Width/(float)Height,10.0f,20.0f);
    glMatrixMode(GL_MODELVIEW); //команды относятся к просмотру
    glLoadIdentity(); //сбрасываем текущую матрицу
}

void drawAnimal() {
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( -2.0f, 1.0f);		// Top
        glVertex2f(-2.0f,-1.0f);		// Bottom Left
        glVertex2f( 0.0f,-1.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( -1.0f, 2.5f);		// Top
        glVertex2f( -2.0f, 1.5f);		// Bottom Left
        glVertex2f( -1.0f,1.5f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 1.0f, 0.0f);		// Top
        glVertex2f( -1.0f, 0.0f);		// Bottom Left
        glVertex2f( 1.0f,-2.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 2.0f, 1.0f);		// Top
        glVertex2f( 1.0f, 0.0f);		// Bottom Left
        glVertex2f( 2.0f,0.0f);		// Bottom Right
    glEnd();
    glBegin(GL_TRIANGLES); // Drawing Using Triangles
        glVertex2f( 1.0f,-1.0f);	    // Top
        glVertex2f( 1.0f,-3.0f);		// Bottom Left
        glVertex2f( 2.0f,-2.0f);			// Bottom Right
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
        glVertex2f(-3.0f, 1.5f);		// Top Left
        glVertex2f( -2.0f, 1.5f);		// Top Right
        glVertex2f( -2.0f,0.5f);		// Bottom Right
        glVertex2f(-3.0f,0.5f);		// Bottom Left
    glEnd();
    glBegin(GL_QUADS);				// Draw A Quad
        glVertex2f(-2.5f,-1.0f);	    // Top Left
        glVertex2f( -1.0f,-1.0f);		// Top Right
        glVertex2f( -1.5f,-2.0f);		// Bottom Right
        glVertex2f(-3.0f,-2.0f);		// Bottom Left
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
