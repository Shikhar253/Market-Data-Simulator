#include "RandomGenerator.h"
#include <cstdlib>

// Function definitions
double generateRandomChange()
{
    return (rand() % 1000 - 500) / 100.0; // Random change between -5 and 5
}

double generateRandomPrice(double currentPrice)
{
    double percentageChange = generateRandomChange();
    return currentPrice * (1 + percentageChange / 100.0);
}
