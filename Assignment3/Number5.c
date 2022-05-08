#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *parent;
    struct node *left;
    struct node *right;
    int data;
    int color;
} node;

typedef struct rbtree
{
    node *root;
    node *NIL;
} rbtree;

void inorder(rbtree *t, node *n)
{
    if (n != t->NIL)
    {
        inorder(t, n->left);

        printf("data : %2d  ",n->data);
        if (n->color == 1)
            printf("color : RED\n");
        else
            printf("color : BLACK\n");

        inorder(t, n->right);
    }
}

void preorder(rbtree* tree, node* n)
{
    if(n != tree->NIL)
    {
        printf("data : %2d  ",n->data);
        if (n->color == 1)
            printf("color : RED\n");
        else
            printf("color : BLACK\n");

        preorder(tree, n->left);
        preorder(tree, n->right);
    }
}

void postorder(rbtree* tree, node* n)
{
    if(n != tree->NIL)
    {
        postorder(tree, n->left);
        postorder(tree, n->right);

        printf("data : %2d  ",n->data);
        if (n->color == 1)
            printf("color : RED\n");
        else
            printf("color : BLACK\n");
    }
}


node *new_node(int data)
{
    node *n = malloc(sizeof(node));

    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->color = 1;

    return n;
}

rbtree *new_rbtree()
{
    rbtree *tree = malloc(sizeof(rbtree));
    node *nil = malloc(sizeof(node));

    nil->parent = NULL;
    nil->left = NULL;
    nil->right = NULL;
    nil->data = 0;
    nil->color = 0;
    tree->NIL = nil;
    tree->root = tree->NIL;

    return tree;
}

void left(rbtree *t, node *n)
{
    node *n2 = n->right;
    n->right = n2->left;

    if (n2->left != t->NIL)
    {
        n2->left->parent = n;
    }

    n2->parent = n->parent;

    if (n == n->parent->left)
    {
        n->parent->left = n2;
    }

    else if (n->parent == t->NIL)
    {
       t->root = n2;
    }

    else
    {
        n->parent->right = n2;
    }

    n2->left = n;
    n->parent = n2;
}

void right(rbtree *t, node *n)
{
    node *n2 = n->left;
    n->left = n2->right;

    if (n2->right != t->NIL)
    {
        n2->right->parent = n;
    }

    n2->parent = n->parent;

    if (n == n->parent->left)
    {
        n->parent->left = n2;
    }

    else if (n->parent == t->NIL)
    {
        t->root = n2;
    }

    else
    {
        n->parent->right = n2;
    }

    n2->right = n;
    n->parent = n2;
}

void fix(rbtree *t, node *z)
{
    while (z->parent->color == 1)
    {
        if (z->parent == z->parent->parent->left)
        {
            node *y = z->parent->parent->right;

            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;

                z = z->parent->parent;
            }

            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left(t, z);
                }

                z->parent->color = 0;
                z->parent->parent->color = 1;

                right(t, z->parent->parent);
            }
        }

        else
        {
            node *y = z->parent->parent->left;

            if (y->color == 1)
            {
                z->parent->color = 0;
                y->color = 0;
                z->parent->parent->color = 1;

                z = z->parent->parent;
            }

            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right(t, z);
                }

                z->parent->color = 0;
                z->parent->parent->color = 1;

                left(t, z->parent->parent);
            }
        }
    }
    t->root->color = 0;
}

void insertion(rbtree *t, node *z)
{
    node *y = t->NIL;
    node *temp = t->root;

    while (temp != t->NIL)
    {
        y = temp;

        if (z->data < temp->data)
            temp = temp->left;

        else
            temp = temp->right;
    }

    z->parent = y;

    if (y == t->NIL)
        t->root = z;

    else if (z->data < y->data)
        y->left = z;

    else
        y->right = z;

    z->left = t->NIL;
    z->right = t->NIL;
    z->color = 1;

    fix(t, z);
}


int main()
{
    rbtree* tree = new_rbtree();

    insertion(tree, new_node(41));
    insertion(tree, new_node(38));
    insertion(tree, new_node(31));
    insertion(tree, new_node(12));
    insertion(tree, new_node(19));
    insertion(tree, new_node(8));

    printf("<Inorder>\n");
    inorder(tree, tree->root);
    printf("-----------------------------------------------------------------\n\n");

    printf("<Preorder>\n");
    preorder(tree, tree->root);
    printf("-----------------------------------------------------------------\n\n");

    printf("<Postorder>\n");
    postorder(tree, tree->root);
    printf("-----------------------------------------------------------------\n\n");


    return 0;
}
