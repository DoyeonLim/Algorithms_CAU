#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	int value;
	int weight;
}knapsack;

int main(void)
{
	knapsack lis[6];

	lis[0].weight = 6;
	lis[1].weight = 10;
	lis[2].weight = 3;
	lis[3].weight = 5;
	lis[4].weight = 1;
	lis[5].weight = 3;

	lis[0].value = 60;
	lis[1].value = 20;
	lis[2].value = 12;
	lis[3].value = 80;
	lis[4].value = 30;
	lis[5].value = 60;

	int capacity = 16;

	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 6; j++)
		{
			if (lis[i].value / lis[i].weight < lis[j].value / lis[j].weight)
			{
				int temp = lis[j].value;
				lis[j].value = lis[i].value;
				lis[i].value = temp;

				temp = lis[j].weight;
				lis[j].weight = lis[i].weight;
				lis[i].weight = temp;
			}
		}
	}

	int max = 0;

	for (int i = 0; i < 6 && capacity>0; i++)
	{
		if (lis[i].weight > capacity)
		{
			printf("item index : %2d | weight : %2d | value : %2d ", i + 1, lis[i].weight, lis[i].value);

			int fraction_num = lis[i].value / lis[i].weight * capacity;
			printf("\n-> fraction %d/%d, fraction number : %d\n", capacity, lis[i].weight, fraction_num);

			max = max + fraction_num;

			capacity = 0;
		}

		else
		{
			capacity = capacity - lis[i].weight;

			printf("item index : %2d | weight : %2d | value : %2d\n", i + 1, lis[i].weight, lis[i].value);
			max = max + lis[i].value;
		}
	}

	printf("\nmaximum = %d", max);

	return 0;
}