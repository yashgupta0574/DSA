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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    Info leftinfo = largestBSTinBT(root->left);
    Info rightinfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftinfo.size + rightinfo.size);

    if (leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && rightinfo.min > root->data)
    {
        // curr.min = min(leftinfo.min, min(rightinfo.min, root->data));
        // curr.max = max(rightinfo.max, max(leftinfo.max, root->data));

        curr.min = leftinfo.min;
        curr.max = rightinfo.max;

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.min = min(leftinfo.min, rightinfo.min);
    curr.max = max(leftinfo.max, rightinfo.max);
    if (leftinfo.max < root->data)
    {
        curr.ans = 1 + leftinfo.ans;
    }
    else if (rightinfo.min > root->data)
    {
        curr.ans = 1 + rightinfo.ans;
    }
    else
    {
        curr.ans = max(leftinfo.ans, rightinfo.ans);
    }

    curr.isBST = false;
    return curr;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(4);
    root->right->right = new node(7);
    cout << largestBSTinBT(root).ans << endl;
    return 0;
}