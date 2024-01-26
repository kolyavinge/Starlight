#include <gl/opengl.h>
#include <freeglut/glut.h>
#include <core/Constants.h>
#include <core/GameManager.h>
#include <render/debug/DebugRenderLogic.h>
#include <render/release/ReleaseRenderLogic.h>
#include <win/resource.h>
#include <win/App.h>

GameManager App::_gameManager;
//DebugRenderLogic renderLogic;
ReleaseRenderLogic renderLogic;
RenderLogic& App::_renderLogic = renderLogic;

void App::Start(int argc, char** argv)
{
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
    _gameManager.InputDevices.Keyboard.Press(key);
}

void App::Keyup(unsigned char key, int, int)
{
    _gameManager.InputDevices.Keyboard.Release(key);
}

void App::JoystickKeypress(unsigned int buttons, int xaxis, int, int)
{
    Joystick& joystick = _gameManager.InputDevices.Joystick;
    joystick.PressButton1(buttons & GLUT_JOYSTICK_BUTTON_A);
    joystick.PressButton2(buttons & GLUT_JOYSTICK_BUTTON_B);
    joystick.PressButton3(buttons & GLUT_JOYSTICK_BUTTON_C);
    joystick.PressLeft(xaxis < 0);
    joystick.PressRight(xaxis > 0);
}

void App::ApplyButtonsToController()
{
    ShipController& playerController = _gameManager.Game.PlayerController;
    Keyboard& keyboard = _gameManager.InputDevices.Keyboard;
    Joystick& joystick = _gameManager.InputDevices.Joystick;

    if (keyboard.IsPressed('w') || joystick.IsButton1Pressed())
    {
        playerController.ActivateThrottle();
    }
    else
    {
        playerController.ReleaseThrottle();
    }

    if (keyboard.IsPressed('s') || joystick.IsButton2Pressed() || joystick.IsButton3Pressed())
    {
        playerController.ActivateBreak();
    }
    else
    {
        playerController.ReleaseBreak();
    }

    if (keyboard.IsPressed('a') || joystick.IsLeftPressed())
    {
        playerController.TurnLeft();
    }
    else if (keyboard.IsPressed('d') || joystick.IsRightPressed())
    {
        playerController.TurnRight();
    }
    else
    {
        playerController.ReleaseTurn();
    }

    if (keyboard.IsPressed(VK_ESCAPE))
    {
        _gameManager.Game.SwitchPause();
        keyboard.Release(VK_ESCAPE);
    }
}

void App::TimerCallback(int)
{
    ApplyButtonsToController();
    _gameManager.UpdateGame();
    glutPostRedisplay();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
}
