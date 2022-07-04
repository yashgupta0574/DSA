// A non-empty binary tree T is balanced if:
// 1) Left subtree of T is balanced
// 2) Right subtree of T is balanced
// 3) The difference between heights of left subtree and right subtree is not more than 1.
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *root;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(node *newroot)
{
    if (newroot == NULL)
    {
        return 0;
    }
    return max(height(newroot->left), height(newroot->right)) + 1;
}

bool isbalanced(node *root) // O(n^2)
{
    if (root == NULL)
    {
        return true;
    }
    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Isbalanced(node *root, int *height) // O(n)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (Isbalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (Isbalanced(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    if (isbalanced(root))
    {
        cout << "Balanced binary tree" << endl;
    }
    else
    {
        cout << "Unbalanced binary tree" << endl;
    }
    int height = 0;
    if (Isbalanced(root, &height))
    {
        cout << "Balanced binary tree" << endl;
    }
    else
    {
        cout << "Unbalanced binary tree" << endl;
    }
    return 0;
}