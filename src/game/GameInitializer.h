#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>

class GameInitializerException : public Exception { };

class GameInitializer : public Object
{
public:
    void Init();

private:
    void InitGL();
    void InitAL();
};
