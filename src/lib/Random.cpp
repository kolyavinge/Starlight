#include <cstdlib>
#include <ctime>
#include <lib/Random.h>

Random::Random()
{
    std::srand((unsigned int)std::time(nullptr));
}

int Random::GetInt(int max)
{
    return std::rand() % max;
}
