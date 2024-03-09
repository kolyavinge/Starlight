#pragma once

#include <lib/Object.h>
#include <gl/FramedTexture.h>

class AnimatedTexturedRect : public Object
{
    FramedTexture* _texture;
    int _currentFrame;
    int _delay;
    int _currentDelay;
    bool _isActive;

public:
    AnimatedTexturedRect(FramedTexture& texture, int delay);

    void Render();
    void Activate();
    bool IsActive();

private:
    void SwitchFrame();
};
