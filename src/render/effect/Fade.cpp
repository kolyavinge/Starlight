#include <gl/opengl.h>
#include <render/effect/Fade.h>

Fade::Fade(FadeDirection direction, int iterationsCount)
{
    _direction = direction;
    _iterationsCount = iterationsCount;
    _isActive = false;
    _step = 1.0f / (float)_iterationsCount;
    if (direction == FadeDirection::ToTransparent)
    {
        _alpha = 1.0f;
        _step = -_step;
    }
    else
    {
        _alpha = 0.0f;
    }
}

bool Fade::IsActive()
{
    return _isActive;
}

void Fade::Activate()
{
    _isActive = true;
}

bool Fade::IsCompleted()
{
    return _iterationsCount == 0;
}

void Fade::Render()
{
    if (!IsActive() || IsCompleted()) return;

    _alpha += _step;
    _iterationsCount--;

    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glColor4f(0.0f, 0.0f, 0.0f, _alpha);

    glBegin(GL_QUADS);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);

    glEnd();
}
