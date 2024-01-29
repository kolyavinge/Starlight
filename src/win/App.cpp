#include <freeglut/glut.h>
#include <core/Constants.h>
#include <render/ui/ScreenRenderer.h>
#include <win/resource.h>
#include <win/App.h>

void App::Start(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize((int)Constants::ScreenWidth, (int)(Constants::ScreenWidth / Constants::ScreenAspect));
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow(Constants::Title);
    SetIcon();
    glutPositionWindow(100, 100);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keypress);
    glutKeyboardUpFunc(Keyup);
    glutJoystickFunc(JoystickKeypress, 10);
    _renderManager.Init();
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
    ScreenRenderer& renderer = _renderManager.GetScreenRenderer(_game.GetCurrentScreen());
    renderer.Render(_game);
    glutSwapBuffers();
}

void App::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void App::Keypress(unsigned char key, int, int)
{
    _game.InputDevices.Keyboard.Press(key);
}

void App::Keyup(unsigned char key, int, int)
{
    _game.InputDevices.Keyboard.Release(key);
}

void App::JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int)
{
    Joystick& joy = _game.InputDevices.Joystick;
    joy.PressButton1(buttons & GLUT_JOYSTICK_BUTTON_A);
    joy.PressButton2(buttons & GLUT_JOYSTICK_BUTTON_B);
    joy.PressButton3(buttons & GLUT_JOYSTICK_BUTTON_C);
    joy.PressLeft(xaxis < 0);
    joy.PressRight(xaxis > 0);
    joy.PressUp(yaxis < 0);
    joy.PressDown(yaxis > 0);
}

void App::TimerCallback(int)
{
    _game.Update();
    glutPostRedisplay();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
}
