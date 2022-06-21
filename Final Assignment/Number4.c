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
char node_name[5];

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

		for (int i = 0; i < 5; i++)
		{
			if (node[i].s == INF && node[i].dst == -1)
			{
				printf("Vertex %c | d = INF, pi = NIL\n", node_name[i]);
			}

			else if (node[i].s == INF)
			{
				printf("Vertex %c | d = INF, pi = %c\n", node_name[i], node_name[node[i].dst]);
			}

			else if (node[i].dst == -1)
			{
				printf("Vertex %c | d = %2d, pi = NIL\n", node_name[i], node[i].s);
			}

			else
			{
				printf("Vertex %c | d = %2d, pi = %c\n", node_name[i], node[i].s, node_name[node[i].dst]);
			}
		}

		printf("\n");
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
	node_name[0] = 's';
	node_name[1] = 't';
	node_name[2] = 'x';
	node_name[3] = 'y';
	node_name[4] = 'z';

	bellmanFord();

	if (graph == 0)
	{
		printf("-> ���� ����Ŭ�� �����ϴ� �׷����Դϴ�.\n");
	}

	else
	{
		printf("-> ���� ����Ŭ�� �������� �ʴ�, �������� �׷����Դϴ�.\n\n");
	}

	return 0;
}