#include <gl/FramedTexture.h>
#include <gl/TextRenderer.h>
#include <game/GLInjectModule.h>

void GLInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<FramedTexture, FramedTextureResolvingFactory>();
    binder.BindSingletonByFactory<TextRenderer, TextRendererResolvingFactory>();
}
