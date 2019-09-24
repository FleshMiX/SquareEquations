#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

const float EPS = 0.000001;

enum nRoots
{
	INF_NUM_ROOTS = -1,
	NO_ROOTS,
	ONE_ROOT,
	TWO_ROOTS
};

/*!
This func checking equality of x & y with spared accuracy EPS
\param[in] b coefficient
\param[in] c coefficient
\return if(x == y) => 1; else 0;
*/

int SparedEquality (float a, float b)
{
	if (abs(a - b) <= EPS)
		return 1;
	else
		return 0;
}

/*!
This func solves linear equation of this kind: bx+c = 0
\param[in] b coefficient
\param[in] c coefficient
\param[out] x1 root of equation
\return number of roots
*/

int LinearSolve (float b, float c, float* x1)
{
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);

	if(SparedEquality(b, 0))
	{
		return (SparedEquality(c, 0)) ? INF_NUM_ROOTS : NO_ROOTS;
	}
	else /*(b != 0)*/
	{
		*x1 = -c/b;
		return ONE_ROOT;
	}
}

/*!
This func solves square equation of this kind: ax^2+bx+c = 0
\param[in] a coefficient
\param[in] b coefficient
\param[in] c coefficient
\param[out] x1 root of equation
\param[out] x2 root of equation
\return number of roots
*/

int SquareSolve (float a, float b, float c, float* x1, float* x2)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);
	
	*x1 = NAN;
	*x2 = NAN;
	
	if (SparedEquality(a, 0)) /* (a ==0 ) */
	{
		return LinearSolve(b, c, x1);
	}
	/*(a != 0 */
	float Discriminant = b*b - 4*a*c;
	if (Discriminant < 0)
		return NO_ROOTS;
	else if(Discriminant == 0)
	{
		*x1 = -b/(2*a);
		return ONE_ROOT;
	}
	float RootedDiscriminant = sqrt(Discriminant);

	*x1 = (-b - RootedDiscriminant)/(2*a);
	*x2 = (-b + RootedDiscriminant)/(2*a);
	return TWO_ROOTS;

}


int utestSquareSolve(void)
{
	printf("---------------------------UTEST-----------------------\n");
	
	float a[9]      = { -1,   1,   1,   1,   -1,   1,  -1,   1,  0 };
	float b[9]   	= { 14,  32, -16,  -6,  -32,  10,  86,   5,   0};
	float c[9]   	= {-49, 256,  28,  13, -256,  16, 651, -24,   0};
	int Nroots[9]	= {  1,   1,   2,   0,    1,   2,   2,   2,  -1};
	float x1[9]		= {  7, -16,   2, NAN,  -16,  -8,  93,  -8, NAN};
	float x2[9]		= {NAN, NAN,  14, NAN,  NAN,  -2,  -7,   3, NAN};
	
	for(int i = 0; i < 9; i++)
	{
		float x1_u = 0;
		float x2_u = 0;
		
		if(SquareSolve(a[i], b[i], c[i], &x1_u, &x2_u) != Nroots[i] || !SparedEquality(x1_u, x1[i]) || !SparedEquality(x2_u, x2[i]))\
		{
			printf("!!!ERROR IN UTEST!!!\n");
			return 1;
		}
		printf("i = %d; Nroots = %d; x1_u = %f; x1_cor = %f\n", i, Nroots[i], x1_u, x1[i]);
	}
	printf("UTEST completed successfully!\n--------------------------------------------------------\n");
	return 0;
}

