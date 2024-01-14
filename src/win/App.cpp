#include <gl/opengl.h>
#include <core/GameConstants.h>
#include <core/GameManager.h>
#include <core/Controller.h>
#include <render/debug/DebugRenderLogic.h>
#include <render/release/ReleaseRenderLogic.h>
#include <win/resource.h>
#include <win/App.h>

//DebugRenderLogic renderLogic;
ReleaseRenderLogic renderLogic;
RenderLogic& App::_renderLogic = renderLogic;
Vector3 App::_upAxis;
Array<bool, 256> App::_keyPressed;
int App::_joyXAxis;
unsigned int App::_joyButtonsPressed;

void App::Start(int argc, char** argv)
{
    _upAxis.Set(0.0f, 0.0f, 1.0f);
    _keyPressed.InitItems(false);
    _joyXAxis = 0;
    _joyButtonsPressed = 0;
    glutInit(&argc, argv);
    const int width = 1200;
    glutInitWindowSize(width, width * 9 / 16);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow(GameConstants::Title);
    SetIcon();
    glutPositionWindow(100, 100);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutJoystickFunc(JoystickKeypress, 10);
    _renderLogic.Init();
    glutTimerFunc(GameConstants::MainTimerMsec, TimerCallback, 0);
    glutMainLoop();
}

void App::SetIcon()
{
    HWND hwnd = FindWindowA(NULL, GameConstants::Title);
    HANDLE icon = LoadImage(GetModuleHandleA(GameConstants::Exe), MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, LR_COLOR);
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)icon);
}

void App::Display()
{
    GameCamera& camera = GameManager::Instance.Game.Camera;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 16.0 / 9.0, 0.0, 1.0);
    gluLookAt(camera.Position, camera.LookAt, _upAxis);
    //gluLookAt(0, 2000, 100, 0, 0, 0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(GameConstants::RenderLineWidth);
    glPointSize(GameConstants::RenderPointSize);
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
