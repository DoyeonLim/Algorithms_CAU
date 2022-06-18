#include <stdio.h>

#define MAX_VERTICES 5
#define INF 1000000
#define FALSE 0
#define TRUE 1

int vertex[MAX_VERTICES][MAX_VERTICES] = {
	{INF, 3, INF, 5, INF},
	{INF, INF, 6, 2, INF},
	{INF, INF, INF, INF, 2},
	{INF, 1, 4, INF, 6},
	{3, INF, 7, INF, INF}
};

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose() 
{
	int min = INF;
	int minpos = -1;

	for (int i = 0; i < 5; i++)
	{
		if (distance[i] < min && found[i] == -1)
		{
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;
}

void path(int start)
{
	for (int i = 0; i < 5; i++)
	{
		distance[i] = vertex[start][i];
		found[i] = -1;
	}

	found[start] = FALSE;
	distance[start] = 0;

	for (int i = 0; i < 4; i++)
	{
		int u = choose();

		found[u] = i;

		for (int w = 0; w < 5; w++)
		{
			if (found[w] == -1)
			{
				if (distance[u] + vertex[u][w] < distance[w])
				{
					distance[w] = distance[u] + vertex[u][w];
				}
			}
		}
	}
}

void print_node_cost()
{
	printf("<Source vertex s to vertice y>\n");

	printf("3");

	int node = 3;

	do
	{
		node = found[node];
		printf(" << %d", node);
	} while (node != 0);

	printf("\nTotal cost = %d\n", distance[3]);

	printf("\n\n<Source vertex s to vertice z>\n");

	printf("4");

	node = 4;

	do 
	{
		node = found[node];
		printf(" << %d", node);
	} while (node != 0);

	printf("\nTotal cost = %d\n", distance[4]);

	printf("\n");
}

int main()
{
	path(0);

	print_node_cost();

	return 0;
}