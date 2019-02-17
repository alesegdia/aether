#include "rng.h"

int aether::math::randi(int min, int max)
{
    return min + randi(max - min);
}

int aether::math::randi(int max)
{
    return std::rand() % max;
}
