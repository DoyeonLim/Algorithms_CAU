#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int lca(Node* list, int t1, int t2)
{
    int n;

    if((list->data == t1) || (list->data == t2))
    {
        n = list->data;
        return n;
    }

    else if((list->data > t1) && (list->data < t2))
    {
        n = list->data;
        return n;
    }

    else if(list->data > t2)
    {
        return lca(list->left, t1, t2);
    }

    else
        return lca(list->right, t1, t2);
}

void tree(Node* list)
{
    list->data = 6;

    Node* left = malloc(sizeof(Node));
    list->left = left;

    Node* right = malloc(sizeof(Node));
    list->right = right;

    left->data = 2;

    left->left = left->right = NULL;
    right->data = 8;

    Node* c;
    Node* d;
    c = malloc(sizeof(Node));
    d = malloc(sizeof(Node));

    left->left = c;
    left->right = d;

    c->data = 1;
    c->left = c->right = NULL;

    d->data = 3;
    d->left = d->right = NULL;

    Node* a;
    Node* b;
    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));

    right->left = a;
    right->right = b;

    a->data = 7;
    a->left = a->right = NULL;

    b->data = 9;
    b->left = b->right = NULL;
}

int main()
{
    int t1 ,t2;
    int temp;

    Node* list= malloc(sizeof(Node));
    tree(list);

    printf("two values : ");
    scanf("%d %d",&t1,&t2);

    if(t1 > t2)
    {
        temp = t2;
        t2 = t1;
        t1 = temp;
    }

    printf("lowest common ancestor : %d",lca(list, t1, t2));

    return 0;
}


