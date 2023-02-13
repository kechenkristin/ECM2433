#include <stdlib.h>
int main ()
{
	int *p = (int *)malloc(20*sizeof(int));

	/*
	 *  oops! forgot to free p
	 free(p);
	 */
	return 0;
}
