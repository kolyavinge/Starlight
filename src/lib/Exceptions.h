#pragma once

#include <lib/Object.h>

class Exception : public Object {};

class ArgumentException : public Object {};

class ObjectStateException : public Object {};

class IndexOutOfBoundsException : public Exception {};

class MemoryAllocationException : public Exception {};

class AssertException : public Exception {};
