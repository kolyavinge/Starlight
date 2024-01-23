#include <gl/opengl.h>

void glTranslatef(Vector3& v)
{
    glTranslatef(v.X, v.Y, v.Z);
}

void glVertex3f(Vector3& v)
{
    glVertex3f(v.X, v.Y, v.Z);
}

void gluLookAt(Vector3& position, Vector3& lookAt, Vector3& upAxis)
{
    gluLookAt(position.X, position.Y, position.Z, lookAt.X, lookAt.Y, lookAt.Z, upAxis.X, upAxis.Y, upAxis.Z);
}

void glTexCoord2f(Point2& p)
{
    glTexCoord2f(p.X, p.Y);
}

void glNormal3f(Vector3& v)
{
    glNormal3f(v.X, v.Y, v.Z);
}

void glScalef(Vector3& v)
{
    glScalef(v.X, v.Y, v.Z);
}
