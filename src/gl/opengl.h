#pragma once

#pragma warning(push, 0)

#include <windows.h>
#include <glew/glew.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <freeglut/glut.h>

#pragma warning(pop)

#include <calc/Vector3.h>

void glTranslatef(Vector3& v);
void glVertex3f(Vector3& v);
void gluLookAt(Vector3& position, Vector3& lookAt, Vector3& upAxis);
