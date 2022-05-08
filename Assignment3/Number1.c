#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node {
    struct Node* next;
    int data;
}Node;

void append(Node* list, int newData)
{
    if (list->next == NULL)
    {
        Node* newNode = malloc(sizeof(Node));

        newNode->data = newData;
        newNode->next = NULL;

        list->next = newNode;
    }

    else
    {
        Node* cur = list;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->data = newData;
        newNode->next = NULL;

        cur->next = newNode;
    }
}

void insert(Node* list, int pos, int data)
{
    Node* cur = list;

    Node* newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if (pos == 0)
    {
        newNode->next = list->next;
        list->next = newNode;
    }

    else
    {
        int count = 0;

        while (count != pos)
        {
            if (count == (pos - 1))
            {
                newNode->next = cur->next;
                cur->next = newNode;
            }
            cur = cur->next;
            count++;
        }
    }
}

void traverse(Node* list, int* val)
{
    while (list->next)
    {
        list = list->next;
        *(val++) = list->data;
    }
}

int delete(Node* list, int element)
{
    Node* cur = list;

    while (cur->next != NULL)
    {
        if (cur->next->data == element)
        {
            Node* removeNode = cur->next;
            cur->next = removeNode->next;
            free(removeNode);

            return 0;
        }
    }

    return -1;
}

Node* reverse(Node* list)
{
    Node* l1, * l2, * l3;

    l1 = list;
    l2 = NULL;

    while (l1 != NULL)
    {
        l3 = l2;
        l2 = l1;
        l1 = l1->next;
        l2->next = l3;
    }

    return l2;
}

int main()
{
    Node* start = malloc(sizeof(Node));
    int* random = malloc(sizeof(int) * 10);
    srand(time(NULL));

    start->next = NULL;

    for (int i = 0; i < 10; i++)
    {
        append(start, rand());
    }

    traverse(start, random);

    printf("Random list : [ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", random[i]);
    }

    printf("]\n");
    free(random);

    Node* rev = malloc(sizeof(Node) * 10);
    rev->next = reverse(start);

    random = malloc(sizeof(int) * 10);

    traverse(rev,random);

    printf("Reverse list : [ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", random[i]);
    }
    printf("]\n");

    return 0;
}
