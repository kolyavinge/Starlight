#include <gl/Face.h>

Face::Face()
{
    this->i0 = 0;
    this->i1 = 0;
    this->i2 = 0;
}

Face::Face(unsigned int i0, unsigned int i1, unsigned int i2)
{
    this->i0 = i0;
    this->i1 = i1;
    this->i2 = i2;
}
