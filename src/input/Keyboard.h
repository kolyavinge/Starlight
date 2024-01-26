#pragma once

#include <lib/Object.h>
#include <lib/Array.h>

class Keyboard : public Object
{
    Array<bool, 256> _keyPressed;

public:
    Keyboard();

    void Press(unsigned char key);
    void Release(unsigned char key);
    bool IsPressed(unsigned char key);
};
