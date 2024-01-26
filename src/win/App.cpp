#include <gl/opengl.h>
#include <freeglut/glut.h>
#include <core/Constants.h>
#include <core/GameManager.h>
#include <core/Controller.h>
#include <render/debug/DebugRenderLogic.h>
#include <render/release/ReleaseRenderLogic.h>
#include <win/resource.h>
#include <win/App.h>

GameManager App::_gameManager;
//DebugRenderLogic renderLogic;
ReleaseRenderLogic renderLogic;
RenderLogic& App::_renderLogic = renderLogic;
Array<bool, 256> App::_keyPressed;
int App::_joyXAxis;
unsigned int App::_joyButtonsPressed;

void App::Start(int argc, char** argv)
{
    _keyPressed.InitItems(false);
    _joyXAxis = 0;
    _joyButtonsPressed = 0;
    glutInit(&argc, argv);
    const int width = 1200;
    glutInitWindowSize(width, (int)((double)width / _screenAspect));
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow(Constants::Title);
    SetIcon();
    glutPositionWindow(100, 100);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutJoystickFunc(JoystickKeypress, 10);
    glPointSize(Constants::RenderPointSize);
    glLineWidth(Constants::RenderLineWidth);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    _renderLogic.Init();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
    glutMainLoop();
}

void App::Shutdown()
{
    PostQuitMessage(0);
}

void App::SetIcon()
{
    HWND hwnd = FindWindowA(NULL, Constants::Title);
    HANDLE icon = LoadImage(GetModuleHandleA(Constants::Exe), MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_COLOR);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)icon);
}

void App::Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, _screenAspect, 0.1, Constants::SceneRadiusDouble);
    Camera& camera = _gameManager.Game.Camera;
    gluLookAt(camera.Position, camera.LookAt, _upAxis);
    //gluLookAt(0, 2000, 100, 0, 0, 0, 0, 0, 1);
    _renderLogic.Render(_gameManager.Game);
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
    Controller& controller = _gameManager.Game.PlayerController;

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

    if (_keyPressed[VK_ESCAPE])
    {
        _gameManager.Game.SwitchPause();
        _keyPressed[VK_ESCAPE] = false;
    }
}

void App::TimerCallback(int)
{
    ApplyButtonsToController();
    _gameManager.Game.Update();
    glutPostRedisplay();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
}
