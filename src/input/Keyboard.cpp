#include <windows.h>
#include <lib/Assert.h>
#include <lib/Memory.h>
#include <input/Keyboard.h>

Keyboard::Keyboard()
{
    _keyStates.InitAll(KeyState::Released);
    Memory::Zero<unsigned char>(_newKeyStates, 256);
}

void Keyboard::Update()
{
    Assert::True(GetKeyboardState(_newKeyStates));
    for (int i = 0; i < _keyStates.Count; i++)
    {
        if (_keyStates[i] == KeyState::Released && IsKeyPressed(_newKeyStates[i]))
        {
            _keyStates[i] = KeyState::Pressed;
        }
        else if (_keyStates[i] == KeyState::Pressed && IsKeyPressed(_newKeyStates[i]))
        {
            _keyStates[i] = KeyState::Held;
        }
        else if (_keyStates[i] == KeyState::Held && !IsKeyPressed(_newKeyStates[i]))
        {
            _keyStates[i] = KeyState::Released;
        }
        else if (_keyStates[i] == KeyState::Pressed && !IsKeyPressed(_newKeyStates[i]))
        {
            _keyStates[i] = KeyState::Released;
        }
    }
}

bool Keyboard::IsPressed(unsigned char key)
{
    return _keyStates[key] == KeyState::Pressed;
}

bool Keyboard::IsHeld(unsigned char key)
{
    return _keyStates[key] == KeyState::Held;
}

bool Keyboard::IsPressedOrHeld(unsigned char key)
{
    return IsPressed(key) || IsHeld(key);
}

bool Keyboard::IsKeyPressed(unsigned char keyState)
{
    return (keyState & 128) > 0;
}
