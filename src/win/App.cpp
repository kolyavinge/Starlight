#include "gl/glut.h"
#include "core/GameConstants.h"
#include "core/GameManager.h"
#include "win/App.h"

DebugRenderLogic App::_renderLogic;

void App::Start(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow(GameConstants::Title);
    glutPositionWindow(50, 50);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
    glutMainLoop();
}

void App::Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _renderLogic.Render(GameManager::Instance.Game);
    glutSwapBuffers();
}

void App::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 16.0 / 9.0, 0.0, 1.0);
    gluLookAt(
        10.0, -40.0, 10.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 1.0);
}

void App::Keypress(unsigned char key, int x, int y)
{
    Controller& controller = GameManager::Instance.Game.PlayerController;

    if (key == 'w') controller.ActivateThrottle();
    if (key == 's') controller.ActivateBreak();
    if (key == 'a') controller.TurnLeft();
    if (key == 'd') controller.TurnRight();
}

void App::Keyup(unsigned char key, int x, int y)
{
    Controller& controller = GameManager::Instance.Game.PlayerController;

    if (key == 'w') controller.ReleaseThrottle();
    if (key == 's') controller.ReleaseBreak();
    if (key == 'a') controller.ReleaseTurn();
    if (key == 'd') controller.ReleaseTurn();
}

void App::TimerCallback(int state)
{
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
}
