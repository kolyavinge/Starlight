#include <gl/opengl.h>
#include <core/GameConstants.h>
#include <core/GameManager.h>
#include <core/Controller.h>
#include <win/App.h>

Vector3d App::_upAxis = Vector3d(0.0f, 0.0f, 1.0f);
DebugRenderLogic App::_renderLogic;
bool App::_keyPressed[256];
int App::_joyXAxis = 0;
unsigned int App::_joyButtonsPressed = 0;

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
    glutJoystickFunc(JoystickKeypress, 10);
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
    glutMainLoop();
}

void App::Display()
{
    GameCamera& camera = GameManager::Instance.Game.Camera;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 16.0 / 9.0, 0.0, 1.0);
    gluLookAt(camera.Position, camera.LookAt, _upAxis);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(GameConstants::RenderLineWidth);
    _renderLogic.Render(GameManager::Instance.Game);
    glutSwapBuffers();
}

void App::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void App::Keypress(unsigned char key, int, int)
{
    _keyPressed[key] = true;
}

void App::Keyup(unsigned char key, int, int)
{
    _keyPressed[key] = false;
}

void App::JoystickKeypress(unsigned int buttons, int xaxis, int, int)
{
    _joyButtonsPressed = buttons;
    _joyXAxis = xaxis;
}

void App::ApplyButtonsToController()
{
    Controller& controller = GameManager::Instance.Game.PlayerController;

    if (_keyPressed['w'] || (_joyButtonsPressed & GLUT_JOYSTICK_BUTTON_A))
    {
        controller.ActivateThrottle();
    }
    else
    {
        controller.ReleaseThrottle();
    }

    if (_keyPressed['s'] || (_joyButtonsPressed & GLUT_JOYSTICK_BUTTON_B) || (_joyButtonsPressed & GLUT_JOYSTICK_BUTTON_C))
    {
        controller.ActivateBreak();
    }
    else
    {
        controller.ReleaseBreak();
    }

    if (_keyPressed['a'] || _joyXAxis < 0)
    {
        controller.TurnLeft();
    }
    else if (_keyPressed['d'] || _joyXAxis > 0)
    {
        controller.TurnRight();
    }
    else
    {
        controller.ReleaseTurn();
    }
}

void App::TimerCallback(int)
{
    ApplyButtonsToController();
    GameManager::Instance.Game.Update();
    glutPostRedisplay();
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
}
