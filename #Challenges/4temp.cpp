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

vector<int> inorder(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return v;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
    return v;
}

int kthLargest(node *root, int K)
{
    vector<int> v;
    v = inorder(root, v);
    int len = v.size();
    return len;
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

    cout << kthLargest(root, 2) << endl;

    return 0;
}