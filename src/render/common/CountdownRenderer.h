#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/TexturedRect.h>

class CountdownRenderer : public Object
{
    Array<TexturedRect*, 4> _countdownItems;

public:
    CountdownRenderer();

    void Init(
        TexturedRect& countdown1Item,
        TexturedRect& countdown2Item,
        TexturedRect& countdown3Item);

    void Render(int countdownNumber, int countdownIteration, int countdownSwitchIteration);
};

class CountdownRendererResolvingFactory : public ResolvingFactory<CountdownRenderer>
{
public:
    CountdownRenderer* Make(Resolver& resolver) override;
};
