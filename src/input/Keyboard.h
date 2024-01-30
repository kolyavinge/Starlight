#pragma once

#include <lib/Object.h>
#include <lib/Array.h>

class Keyboard : public Object
{
    enum class KeyState
    {
        Released,
        Pressed,
        Held
    };

    Array<KeyState, 256> _keyStates;
    unsigned char _newKeyStates[256];

public:
    Keyboard();

    void Update();
    bool IsPressed(unsigned char key);
    bool IsHeld(unsigned char key);

private:
    bool IsKeyPressed(unsigned char keyState);
};
