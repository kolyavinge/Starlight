#pragma once

class ITexturedRect
{
public:
    virtual void Render() = 0;
    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;
};
