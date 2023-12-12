#include "gl/opengl.h"

void glTranslatef(Vector3d& v)
{
    glTranslatef(v.X, v.Y, v.Z);
}

void glVertex3f(Vector3d& v)
{
    glVertex3f(v.X, v.Y, v.Z);
}
