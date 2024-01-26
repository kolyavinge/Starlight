#include <input/Keyboard.h>

Keyboard::Keyboard()
{
    _keyPressed.InitItems(false);
}

void Keyboard::Press(unsigned char key)
{
    _keyPressed[key] = true;
}

void Keyboard::Release(unsigned char key)
{
    _keyPressed[key] = false;
}

bool Keyboard::IsPressed(unsigned char key)
{
    return _keyPressed[key];
}
