#include "push_swap.h"


int main (int argc, char **argv)
{
	int *res;
	int i;
	i = 0;
	res = splitmain(argc, argv);
	if (!res)
		return (1);
	while(i < argc - 1)
	{
		printf("%d",res[i]);
		i++;
	}
	
}