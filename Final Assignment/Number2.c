#include <stdio.h>

#define INF 1000000

int graph[8][8] = {
		{0, 1, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 1, 0}
};

typedef enum color {
	WHITE, GRAY, BLACK
} color;

typedef struct Node {
	int s;
	int dst;
	color color;
} Node;

Node node[8];
char node_name[8];

void print_table()
{
	printf("<Display the d and pi values for all vertices>\n\n");
	printf(" n |  d  |  pi\n");
	printf("--------------\n");

	for (int i = 0; i < 8; i++)
	{
		if (node[i].dst == -1)
		{
			printf(" %c |  %d  | NIL\n", node_name[i], node[i].s);
		}

		else
		{
			printf(" %c |  %d  | %c\n", node_name[i], node[i].s, node_name[node[i].dst]);
		}

	}
}

int main() 
{
	int n = 1;

	int queue[50];
	int front;
	int f, r;
	f = r = 0;

	node_name[0] = 'r';
	node_name[1] = 's';
	node_name[2] = 't';
	node_name[3] = 'u';
	node_name[4] = 'v';
	node_name[5] = 'w';
	node_name[6] = 'x';
	node_name[7] = 'y';

	for (int i = 0; i < 8; i++) 
	{
		node[i].color = WHITE;
		node[i].s = INF;
		node[i].dst = -1;
	}

	node[n].color = GRAY;
	node[n].s = 0;

	queue[r++] = n;

	while (f < r) 
	{
		front = queue[f++];

		for (int i = 0; i < 8; i++) 
		{
			if (graph[front][i] == 1)
			{
				if (node[i].color == WHITE) 
				{
					node[i].color = GRAY;
					node[i].s = node[front].s + 1;
					node[i].dst = front;

					queue[r++] = i;
				}
			}
		}

		node[front].color = BLACK;
	}

	print_table();

	return 0;
}