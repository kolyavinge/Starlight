#include <lib/Exceptions.h>
#include <gl/AnimatedTexturedRect.h>

AnimatedTexturedRect::AnimatedTexturedRect(FramedTexture& texture, int delay)
{
    if (delay <= 0) throw ArgumentException();
    _texture = &texture;
    _currentFrame = 0;
    _delay = delay;
    _currentDelay = 0;
    _isActive = false;
}

void AnimatedTexturedRect::Render()
{
    if (!_isActive) return;
    _texture->RenderFrame(_currentFrame);
    SwitchFrame();
}

void AnimatedTexturedRect::Activate()
{
    _isActive = true;
}

bool AnimatedTexturedRect::IsActive()
{
    return _isActive;
}

void AnimatedTexturedRect::SwitchFrame()
{
    _currentDelay++;
    if (_currentDelay == _delay)
    {
        _currentDelay = 0;
        _currentFrame++;
        if (_currentFrame == _texture->GetFramesCount())
        {
            _currentFrame = 0;
            _isActive = false;
        }
    }
}
