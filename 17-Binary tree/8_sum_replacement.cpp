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

void sumreplace(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumreplace(root->left);
    // sumreplace(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    sumreplace(root->right);
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
    preorder(root);
    sumreplace(root);
    cout << endl;
    preorder(root);

    return 0;
}