#pragma once
#define CLOCKS_PER_MS (CLOCKS_PER_SEC*1/10e3)
#include <thread>
void wait(long double delay);
int checkSpeed();
long double klock();
int cls();
double bell(int tick , int i,int max = 5);