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

bool isidentical_BST(node *root1, node *root2)
{
    bool cond1;
    bool cond2;
    bool cond3;
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        cond1 = root1->data == root2->data;
        cond2 = isidentical_BST(root1->left, root2->left);
        cond3 = isidentical_BST(root1->right, root2->right);
    }
    if (cond1 && cond2 && cond3)
    {
        return true;
    }
    return false;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(5);

    if (isidentical_BST(root, root1))
    {
        cout << "BST are identical";
    }
    else
    {
        cout << "BST are not identical";
    }
    return 0;
}