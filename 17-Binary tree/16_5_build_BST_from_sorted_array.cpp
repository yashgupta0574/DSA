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

node *buildBST(int arr[], int min, int max)
{
    if (min > max)
    {
        return NULL;
    }
    int mid = (min + max) / 2;
    node *root = new node(arr[mid]);
    root->left = buildBST(arr, min, mid - 1);
    root->right = buildBST(arr, mid + 1, max);
    return root;
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
    int arr[] = {10, 20, 30, 40, 50};
    node *root = buildBST(arr, 0, 4);
    preorder(root);

    return 0;
}