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

int count_all_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count_all_nodes(root->left) + count_all_nodes(root->right) + 1;
}

int sum_all_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum_all_nodes(root->left) + sum_all_nodes(root->right) + root->data;
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
    cout << count_all_nodes(root) << endl;
    cout << sum_all_nodes(root) << endl;

    return 0;
}