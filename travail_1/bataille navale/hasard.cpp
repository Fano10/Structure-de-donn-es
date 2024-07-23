#include <iostream>
#include <random>
#include <windows.h>
#include "hasard.h"
using namespace std;

typedef std::mt19937 MyRNG;                 // the Mersenne Twister with a popular choice of parameters
uint64_t seed_val = GetTickCount64();       // populate somehow  (avec le temps du système dans ce cas)
MyRNG rng;                                  // e.g. keep one global instance (per thread)

void initialize()
{
    rng.seed((long)seed_val);
}

int recupererValeurAleatoire(int min, int max)
{
    uniform_int_distribution<uint64_t> uint_distMax(min, max);
    return (int)uint_distMax(rng);          // Surcharge de l'operateur ( )
}