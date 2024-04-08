#include <glew/glew.h>
#include <gl/opengl.h>
#include <openal/al.h>
#include <openal/alc.h>
#include <core/Constants.h>
#include <game/GameInitializer.h>

void GameInitializer::Init()
{
    InitGL();
    InitAL();
}

void GameInitializer::InitGL()
{
    glPointSize(Constants::RenderPointSize);
    glLineWidth(Constants::RenderLineWidth);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (glewInit() != GLEW_NO_ERROR) throw GameInitializerException();
}

void GameInitializer::InitAL()
{
    ALCdevice* device = alcOpenDevice(nullptr);
    if (device == nullptr) throw GameInitializerException();
    ALCcontext* context = alcCreateContext(device, nullptr);
    if (!alcMakeContextCurrent(context)) throw GameInitializerException();
}
