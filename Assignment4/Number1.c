#include <stdio.h>
#pragma warning(disable : 4996)

int fibonacci(int n)
{
	if (n <= 2)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
	int n;

	printf("n = ");
	scanf("%d", &n);

	printf("%d", fibonacci(n));

	return 0;
}