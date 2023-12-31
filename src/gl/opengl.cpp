#include <gl/opengl.h>

void glTranslatef(Vector3d& v)
{
    glTranslatef(v.X, v.Y, v.Z);
}

void glVertex3f(Vector3d& v)
{
    glVertex3f(v.X, v.Y, v.Z);
}

void gluLookAt(Vector3d& position, Vector3d& lookAt, Vector3d& upAxis)
{
    gluLookAt(position.X, position.Y, position.Z, lookAt.X, lookAt.Y, lookAt.Z, upAxis.X, upAxis.Y, upAxis.Z);
}
