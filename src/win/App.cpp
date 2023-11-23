#include "windows.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include "gl/glut.h"
#include "lib/List.h"

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(0.0f, 0.0f, -2.0f);
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);

    glVertex3f(100.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    glVertex3f(100.0f, 100.0f, 0.0f);

    glEnd();

    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 16.0 / 9.0, 1.0, 3.0);
    //glMatrixMode(GL_MODELVIEW);
    //gluLookAt(500, 500, 0, 500, 500, 100, 1, 0, 0);
}

void Keypress(unsigned char key, int x, int y)
{
}

void Keyup(unsigned char key, int x, int y)
{
}

int main(int argc, char** argv)
{
    List<int> l(11);
    l.Insert(0, 2);
    l.Insert(0, 20);
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Starlight");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutMainLoop();

    return 0;
}
