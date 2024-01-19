#pragma once

#include <lib/Object.h>

class Exception : public Object {};

class ArgumentException : public Object {};

class ObjectStateException : public Object {};

class IndexOutOfBoundsException : public Exception {};
