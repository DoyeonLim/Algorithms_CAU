#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
}Node;

void remove_duplicates(struct Node *list)
{
    struct Node *ptr1, *ptr2, *val;
    ptr1 = list;

        while((ptr1 != NULL) && (ptr1->next != NULL))
        {
            ptr2 = ptr1;

            while(ptr2->next != NULL)
            {

                if(ptr1->data == ptr2->next->data)
                {
                    val = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    free(val);
                }

                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
}

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

void random_list(Node* list)
{

    int i, j;
    int random[20];
    srand(time(NULL));

    for (i = 0; i < 20; i++)
    {
        random[i] = rand() % 49 + 1;
    }

    int size = sizeof(random) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        append(list, random[i]);
    }
}

Node* get_list()
{
    Node* newList = malloc(sizeof(Node));

    newList->data = 0;
    newList->next = NULL;

    return newList;
}

void show_list(Node* list)
{
    Node* cur = list->next;
    printf("[ ");

    while (cur != NULL)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }

    printf("]\n");
}

int main()
{
    Node* list = get_list();
    random_list(list);
    printf("\n Original list : ");
    show_list(list);

    remove_duplicates(list);
    printf("\n Remove duplicates value list : ");
    show_list(list);
}
