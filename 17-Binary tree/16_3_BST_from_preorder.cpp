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

node *constructBST(int preorder[], int *preorderidx, int ele, int min, int max, int n)
{
    if (*preorderidx >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (ele > min && ele < max)
    {
        root = new node(ele);
        *preorderidx += 1;
        if (*preorderidx < n)
        {
            root->left = constructBST(preorder, preorderidx, preorder[*preorderidx], min, ele, n);
        }
        if (*preorderidx < n)
        {
            root->right = constructBST(preorder, preorderidx, preorder[*preorderidx], ele, max, n);
        }
    }
    return root;
}

void printpreorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 15, 11};
    int n = 5;
    int preorderidx = 0;
    node *newroot = constructBST(preorder, &preorderidx, preorder[preorderidx], INT_MIN, INT_MAX, n);
    printpreorder(newroot);
    return 0;
}