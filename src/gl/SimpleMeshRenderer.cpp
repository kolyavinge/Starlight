#include <gl/opengl.h>
#include <gl/SimpleMeshRenderer.h>

SimpleMeshRenderer::SimpleMeshRenderer()
{
    _activeTextureIndex = 0;
}

void SimpleMeshRenderer::Render(Mesh& mesh)
{
    glEnable(GL_TEXTURE_2D);
    mesh.Textures[_activeTextureIndex].Bind();
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < mesh.Faces.GetCount(); i++)
    {
        Face& face = mesh.Faces[i];

        glNormal3f(mesh.NormalCoords[face.i0]);
        glTexCoord2f(mesh.TextureCoords[face.i0]);
        glVertex3f(mesh.VertexCoords[face.i0]);

        glNormal3f(mesh.NormalCoords[face.i1]);
        glTexCoord2f(mesh.TextureCoords[face.i1]);
        glVertex3f(mesh.VertexCoords[face.i1]);

        glNormal3f(mesh.NormalCoords[face.i2]);
        glTexCoord2f(mesh.TextureCoords[face.i2]);
        glVertex3f(mesh.VertexCoords[face.i2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void SimpleMeshRenderer::SetActiveTextureIndex(int textureIndex)
{
    _activeTextureIndex = textureIndex;
}
