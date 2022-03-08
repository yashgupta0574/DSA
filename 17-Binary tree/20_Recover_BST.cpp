#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcpointers(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calcpointers(root->left, first, mid, last, prev);
    if (*prev && (*prev)->data > root->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcpointers(root->right, first, mid, last, prev);
}

void restoreBST(node *root)
{
    node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;
    calcpointers(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(7);
    root->left->right = new node(2);
    root->right->left = new node(11);
    root->right->right = new node(20);
    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);
    cout << endl;
    return 0;
}