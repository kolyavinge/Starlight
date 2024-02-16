#include <gl/opengl.h>
#include <render/effect/FadeEffect.h>

FadeEffect::FadeEffect(FadeDirection direction, int iterationsCount)
{
    _direction = direction;
    _iterationsCount = iterationsCount;
    Reset();
}

bool FadeEffect::IsActive()
{
    return _currentIteration > 0;
}

void FadeEffect::Activate()
{
    _currentIteration = _iterationsCount;
}

bool FadeEffect::IsCompleted()
{
    return _currentIteration == 0;
}

void FadeEffect::Reset()
{
    _currentIteration = 0;
    _step = 1.0f / (float)_iterationsCount;
    if (_direction == FadeDirection::ToTransparent)
    {
        _alpha = 1.0f;
        _step = -_step;
    }
    else
    {
        _alpha = 0.0f;
    }
}

void FadeEffect::Render()
{
    if (IsActive())
    {
        _alpha += _step;
        _currentIteration--;
    }

    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glColor4f(0.0f, 0.0f, 0.0f, _alpha);

    glBegin(GL_QUADS);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);

    glEnd();
}
