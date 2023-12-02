#include "windows.h"
#include "gl/glut.h"
#include "core/GameConstants.h"
#include "core/GameManager.h"

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
    gluPerspective(45.0, 16.0 / 9.0, 0.1, 10.0);
    gluLookAt(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}

void Keypress(unsigned char key, int x, int y)
{
    Controller& controller = GameManager::Instance.Game.PlayerController;

    if (key == 'w') controller.ActivateThrottle();
    if (key == 's') controller.ActivateBreak();
    if (key == 'a') controller.TurnLeft();
    if (key == 'd') controller.TurnRight();
}

void Keyup(unsigned char key, int x, int y)
{
    Controller& controller = GameManager::Instance.Game.PlayerController;

    if (key == 'w') controller.ReleaseThrottle();
    if (key == 's') controller.ReleaseBreak();
    if (key == 'a') controller.ReleaseTurn();
    if (key == 'd') controller.ReleaseTurn();
}

void TimerCallback(int state)
{
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Starlight");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
    glutMainLoop();

    return 0;
}
