#include <stdio.h>
float radius(float); /* Declare the radius function */
int main()
{
	float A = 23.4;
	float r;
	r = radius(A);
	printf("The radius of a circle with area %f is %f\n", A, r);
	return 0;
}
