#include <cstdlib>
#include <ctime>
#include <lib/Random.h>

using namespace std;

Random::Random()
{
    srand((unsigned int)time(nullptr));
}

int Random::GetIntFromZeroToN(int n)
{
    return rand() % n;
}

int Random::GetIntFromZeroToMax()
{
    return rand();
}

float Random::GetFloatFromZeroToOne()
{
    return (float)rand() / (float)RAND_MAX;
}

float Random::GetFloatFromZeroToN(float n)
{
    return (float)rand() / ((float)RAND_MAX / n);
}

float Random::GetFloatFromZeroToMax()
{
    return (float)rand() / (float)rand();
}
