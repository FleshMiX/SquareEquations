#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square.h"

enum nRoots
{
	INF_NUM_ROOTS = -1,
	NO_ROOTS,
	ONE_ROOT,
	TWO_ROOTS
};


int main ()
{
	utestSquareSolve();
	
	printf("This program solves square equation of this kind: Ax^2+Bx+C = 0\nEnter A, B, C: ");
	float a = NAN, b = NAN, c = NAN;
	while(scanf("%f %f %f", &a, &b, &c) != 3)
	{
		printf("Wrong entry(\nTry again!\n");
		printf("This program solves square equation of this kind: Ax^2+Bx+C = 0\nEnter A, B, C: ");
		fflush(stdin);
	}
	float x1 = NAN, x2 = NAN;

	int nRoots = SquareSolve(a, b, c, &x1, &x2);
	
	switch(nRoots){
	case 0:
		printf("This equation have no roots:(\n");
		break;
	case 1:
		printf("This equation have one root (x = %g)\n", x1);
		break;
	case 2:
		printf("This equation have two roots (x1 = %g , x2 = %g)\n", x1, x2);
		break;
	case INF_NUM_ROOTS:
		printf("This equation have infinite number of roots))\n");
		break;
	default:
		printf("ERROR: Equation have %d roots!\n", nRoots);
		return 1;
	}
	
	return 0;
}
