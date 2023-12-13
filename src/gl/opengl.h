#pragma once

#pragma warning(push, 0)

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#pragma warning(pop)

#include <calc/Vector3d.h>

void glTranslatef(Vector3d& v);
void glVertex3f(Vector3d& v);
