#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int num[8];
int matrix[8][11][11];
int a[11][11];
int b[11][11];

void make_matrix()
{
	printf("Matrix -> ");
	scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);

	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < num[i - 1] + 1; j++)
		{
			for (int k = 1; k < num[i] + 1; k++)
			{
				matrix[i][j][k] = rand() % 100;
			}
		}
	}

	return matrix;
}

static int* matrix_cal(static int* n1, static int* n2, int n3, int n4, int cen) 
{
	int* ans = (int*)malloc(sizeof(int) * 121);

	for (int i = 1; i < num[n3] + 1; i++) 
	{
		for (int j = 1; j < num[n4] + 1; j++) 
		{
			*(ans + i * 11 + j) = 0;

			for (int k = 1; k < num[cen] + 1; k++) 
			{
				*(ans + i * 11 + j) = *(ans + i * 11 + j) + *(n1 + i * 11 + k) * *(n2 + k * 11 + j);
			}
		}
	}

	return ans;
}

static int* re(int first, int finish) 
{
	int* n1, * n2;
	int * ans;

	if (first == finish) 
	{
		printf(" %d ", first);

		return *(matrix + first);
	}

	printf("(");

	n1 = re(first, b[first][finish]);
	n2 = re(b[first][finish] + 1, finish);

	ans = matrix_cal(n1, n2, first - 1, finish, b[first][finish]);

	printf(")");

	return ans;
}

void output_matrix()
{
	int* result;

	printf("\nOutput Matrix\n");

	for (int i = 1; i < num[0] + 1; i++)
	{
		for (int j = 1; j < num[3] + 1; j++)
		{
			printf("%10d", *(result + i * 11 + j));
		}
		printf("\n");
	}
}

int main() 
{
	srand(time(NULL));

	int min;
	int* result;

	make_matrix();

	for (int k = 2; k < 4; k++) 
	{
		for (int i = 1; i <= 3 - k + 1; i++) 
		{
			int j = i + k - 1;

			a[i][j] = 1e5;

			for (int k = i; k < j; k++) 
			{
				min = a[i][k] + a[k + 1][j] + num[i - 1] * num[k] * num[j];

				if (min < a[i][j]) 
				{
					b[i][j] = k;
					a[i][j] = min;
				}
			}
		}
	}

	printf("\nMinimum number of computations = %d\n", a[1][3]);
	
	printf("Optimal chain order = ");
	result = re(1, 3);
	printf("\n");

	output_matrix();

	return 0;
}