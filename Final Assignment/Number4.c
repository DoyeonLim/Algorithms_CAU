#include <stdio.h>

#define INF 1000000
#define TRUE 1
#define FALSE 0

int vertex[5][5] = {
		{INF, 5, INF, 6, INF},
		{INF, INF, 5, 8, -4},
		{INF, -2, INF, INF, INF},
		{INF, INF, -3, INF, 9},
		{2, INF, 4, INF, INF}
};

typedef struct edge
{
	int s;
	int dst;
} edge;

int graph;
edge node[5];

void bellmanFord()
{
	graph = TRUE;

	for (int i = 0; i < 5; i++)
	{
		node[i].s = INF;
		node[i].dst = -1;
	}

	node[0].s = 0;

	for (int n = 1; n < 5; n++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (vertex[i][j] != INF)
				{
					if (node[i].s != INF && (node[j].s > (node[i].s + vertex[i][j])))
					{
						node[j].s = node[i].s + vertex[i][j];
						node[j].dst = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5 && graph; i++)
	{
		for (int j = 0; j < 5 && graph; j++)
		{
			if (vertex[i][j] != INF)
			{
				if (node[i].s != INF && (node[j].s > (node[i].s + vertex[i][j])))
				{
					graph = FALSE;
				}
			}
		}
	}
}

int main()
{
	bellmanFord();

	if (graph == 0)
	{
		printf("음의 사이클이 존재하는 그래프입니다.\n");
	}

	else
	{
		printf("음의 사이클이 존재하지 않는, 정상적이 그래프입니다.\n\n");

		for (int i = 0; i < 5; i++)
		{
			printf("Vertex %2d  d = %2d, pi = %2d\n", i, node[i].s, node[i].dst);
		}
	}

	return 0;
}