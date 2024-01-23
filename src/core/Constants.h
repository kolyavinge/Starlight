#pragma once

class Constants
{
public:
    inline static const float TimeStep = 0.1f;

    inline static const unsigned int MainTimerMsec = 20;

    inline static const float RenderLineWidth = 1.0f;

    inline static const float RenderPointSize = 1.0f;

    inline static const float SceneRadius = 1000.0f;

    inline static const float SceneRadiusDouble = 2.0f * SceneRadius;

    inline static const char* Title = "Starlight\0";

    inline static const char* Exe = "Starlight.exe\0";
};