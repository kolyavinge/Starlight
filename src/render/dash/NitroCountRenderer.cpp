#include <gl/opengl.h>
#include <lib/NumericConverter.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/dash/NitroCountRenderer.h>

NitroCountRenderer::NitroCountRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer),
    _nitrosString(L"NITRO:")
{
}

void NitroCountRenderer::Render(NitroCollection& nitros)
{
    _nitrosCountString.Clear();
    _nitrosCountString.Append(_nitrosString);
    NumericConverter::IntToString(nitros.GetCount(), _nitrosCountString);

    glColor3f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor);
    glPushMatrix();
    float width = (float)_nitrosCountString.GetLength() * _textRenderer.GetLetterWidth();
    glTranslatef((Constants::ScreenWidth - width - 400.0f), 10.0f, 0.0f);
    _textRenderer.Render(_nitrosCountString);
    glPopMatrix();
}

NitroCountRenderer* NitroCountRendererResolvingFactory::Make(Resolver& resolver)
{
    return new NitroCountRenderer(resolver.Resolve<TextRenderer>());
}
