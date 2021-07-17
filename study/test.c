#include <stdio.h>
#include <limits.h>
#include <string.h>


int main()
{
	int dif = strncmp("9", "2000", 15);

	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);

	printf("%ld\n", LONG_MAX);
	printf("%ld\n", LONG_MIN);

	printf("%d\n\n", dif);
	if ("123" > "-1234")
		printf("yes\n");
	else
		printf("no\n");
	
}