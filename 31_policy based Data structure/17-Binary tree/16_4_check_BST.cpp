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

bool check_BST(node *root, node *min, node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool checkleft = check_BST(root->left, min, root);
    bool checkright = check_BST(root->right, root, max);
    return checkleft && checkright;
}

int main()
{
    node *root = new node(7);
    root->left = new node(4);
    root->right = new node(9);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(8);
    root->right->right = new node(10);
    if (check_BST(root, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Invalid BST" << endl;
    }
    return 0;
}