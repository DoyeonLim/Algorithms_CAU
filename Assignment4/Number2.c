#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int main()
{
	int matrix[8][11][11];
	int m1[11][11];
	int m2[11][11];
	int num[8];

	srand(time(NULL));

	int* result;
	int min;

	printf("Matrix <?,?,?,?> = ");
	scanf("<%d,%d,%d,%d>", &num[0], &num[1], &num[2], &num[3]);

	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < num[i - 1] + 1; j++)
		{
			for (int k = 1; k < num[i] + 1; k++)
			{
				matrix[i][j][k] = rand();
			}
		}
	}

	for (int k = 2; k <= 3; k++)
	{
		for (int i = 1; i <= 3 - k + 1; i++)
		{
			int j = i + k - 1;

			m1[i][j] = 1e5;

			for (int k = i; k < j; k++)
			{
				min = m1[i][k] + m1[k + 1][j] + num[i - 1] * num[k] * num[j];

				if (min < m1[i][j])
				{
					m1[i][j] = min;
					m2[i][j] = k;
				}
			}
		}
	}

	printf("Minimum number of computations = %d\n", m1[1][3]);

	printf("Optimal chain order = ");
	result = recursion(1, 3);
	printf("\n");

	printf("Output Matrix\n");

	for (int i = 1; i < num[0] + 1; i++)
	{
		for (int j = 1; j < num[3] + 1; j++)
		{
			printf("%6d", *(result + i * 11 + j));
		}
		printf("\n");
	}

	return 0;
}

int* matrix_cal(static int* n1, static int* n2, int n3, int mid, int n4) 
{
	int num[8];

	int* result = (int*)malloc(sizeof(int) * 121);

	for (int i = 1; i < num[n3] + 1; i++) 
	{
		for (int j = 1; j < num[n4] + 1; j++) 
		{
			*(result + i * 11 + j) = 0;

			for (int k = 1; k < num[mid] + 1; k++) 
			{
				*(result + i * 11 + j) = *(result + i * 11 + j) + *(n1 + i * 11 + k) * *(n2 + k * 11 + j);
			}
		}
	}
	return result;
}

int* recursion(int first, int finish) 
{
	int* n1, * n2;
	int * result;

	int matrix[8][11][11];
	int m2[11][11];

	if (first == finish) 
	{
		printf(" %d ", first);

		return *(matrix + first);
	}

	printf("(");
	
	n1 = recursion(first, m2[first][finish]);
	n2 = recursion(m2[first][finish] + 1, finish);
	result = matrix_cal(n1, n2, first - 1, m2[first][finish], finish);

	printf(")");

	return result;
}