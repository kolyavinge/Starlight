#include <ui/Screen.h>

Screen::Screen(
    ScreenKind kind,
    IScreenNavigator& navigator,
    InputDevices& inputDevices) :
    Kind(kind),
    _navigator(navigator),
    _inputDevices(inputDevices)
{
}

void Screen::Activate(Screen*)
{
}

void Screen::Deactivate()
{
}

void Screen::Update()
{
}

void Screen::ProcessInput()
{
}
