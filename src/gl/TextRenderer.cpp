#include <gl/opengl.h>
#include <anx/GraphicResources.h>
#include <gl/ImageFile.h>
#include <gl/TextRenderer.h>

TextRenderer::TextRenderer()
{
    _textureCoords.InitAll(0.0f);
    _textureStep = 0.0f;
    _letterWidth = 0.0f;
    _letterHeight = 0.0f;
}

void TextRenderer::Init()
{
    String alph(L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ+-*/.,: \0");
    String filePath = GraphicResources::GetAlphabetFilePath();
    _alphTexture.Load(filePath);
    ImageFile image(filePath.GetWCharBuf());
    _textureStep = 1.0f / (float)alph.GetLength();
    _letterWidth = (float)image.GetWidth() / (float)alph.GetLength();
    _letterHeight = (float)image.GetHeight();
    for (int i = 0; i < alph.GetLength(); i++)
    {
        unsigned char ch = (unsigned char)alph[i];
        _textureCoords[ch] = (float)i * _textureStep;
    }
}

void TextRenderer::Render(String& text)
{
    glEnable(GL_TEXTURE_2D);
    _alphTexture.Bind();
    glBegin(GL_QUADS);
    float x = 0.0f;
    for (int i = 0; i < text.GetLength(); i++)
    {
        unsigned char ch = (unsigned char)text[i];
        float textureCoord = _textureCoords[ch];

        glTexCoord2f(textureCoord, 0.0f);
        glVertex2f(x, 0.0f);

        glTexCoord2f(textureCoord + _textureStep, 0.0f);
        glVertex2f(x + _letterWidth, 0.0f);

        glTexCoord2f(textureCoord + _textureStep, 1.0f);
        glVertex2f(x + _letterWidth, _letterHeight);

        glTexCoord2f(textureCoord, 1.0f);
        glVertex2f(x, _letterHeight);

        x += _letterWidth;
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

float TextRenderer::GetLetterWidth()
{
    return _letterWidth;
}

float TextRenderer::GetLetterHeight()
{
    return _letterHeight;
}

TextRenderer* TextRendererResolvingFactory::Make(Resolver&)
{
    return new TextRenderer();
}
