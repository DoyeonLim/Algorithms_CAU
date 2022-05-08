#include <stdio.h>

typedef char bool;
#define FALSE 0
#define TRUE 1

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int arr[1024];
int n = 0;

void inorder(Node* list)
{
    if (list == NULL)
        return;

    inorder(list->left);
    arr[n++] = list->data;
    inorder(list->right);
}

bool chk(Node* list)
{
    inorder(list);

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
            return FALSE;

    }

    return TRUE;
}

void tree(Node* list)
{
    list->data = 8;

    Node* left = malloc(sizeof(Node));
    list->left = left;

    Node* right = malloc(sizeof(Node));
    list->right = right;
    left->data = 3;

    left->left = left->right = NULL;
    right->data = 9;

    Node* a;
    Node* b;
    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));

    right->left = a;
    right->right = b;
    a->data = 4;

    a->left = a->right = NULL;
    b->data = 7;
    b->left = b->right = NULL;
}

int main()
{
    Node* list = malloc(sizeof(Node));
    tree(list);

    if (chk(list))
        printf("It is a valid binary search tree(BST)");
    else
        printf("It is not a valid binary search tree(BST)");

    return 0;

}
