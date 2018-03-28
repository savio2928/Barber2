#include "Random.h"
#include <ctime>
#include <cstdlib>

//creates a random value by taking in the maximum value and displays a random number from 1 to that maximum value.
int RandomValue(int MaxLimit)
{
    srand(time(NULL));
    return (rand()% MaxLimit + 1);
}
