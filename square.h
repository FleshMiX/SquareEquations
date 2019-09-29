#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

int LinearSolve(float b, float c, float* x1);
int SparedEquality(float a, float b);
int SquareSolve(float a, float b, float c, float* x1, float* x2);
int utestSquareSolve(void);
void flush_input(void);

#endif
