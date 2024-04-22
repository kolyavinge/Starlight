#include <freeglut/glut.h>
#include <core/Constants.h>
#include <game/GameFactory.h>
#include <win/resource.h>
#include <win/App.h>

void App::Start(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize((int)Constants::ScreenWidth, (int)Constants::ScreenHeight);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutCreateWindow(Constants::Title);
    SetIcon();
    glutPositionWindow(100, 100);
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutJoystickFunc(JoystickKeypress, 10);
    GameFactory::MakeGameInitializer().Init();
    _game = &GameFactory::MakeNewGame();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
#ifdef RELEASE
    glutFullScreen();
#endif
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
    _game->RenderCurrentScreen();
    glutSwapBuffers();
}

void App::Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

void App::JoystickKeypress(unsigned int buttons, int xaxis, int yaxis, int)
{
    Joystick& joy = _game->InputDevices.Joystick;
    joy.PressButton1(buttons & GLUT_JOYSTICK_BUTTON_A);
    joy.PressButton2(buttons & GLUT_JOYSTICK_BUTTON_B);
    joy.PressButton3(buttons & GLUT_JOYSTICK_BUTTON_C);
    joy.PressButton4(buttons & GLUT_JOYSTICK_BUTTON_D);
    joy.PressLeft(xaxis < 0);
    joy.PressRight(xaxis > 0);
    joy.PressUp(yaxis < 0);
    joy.PressDown(yaxis > 0);
}

void App::TimerCallback(int)
{
    _game->UpdateCurrentScreen();
    _game->UpdateCurrentRenderer();
    _game->VoiceCurrentScreen();
    glutPostRedisplay();
    glutTimerFunc(Constants::MainTimerMsec, TimerCallback, 0);
}
