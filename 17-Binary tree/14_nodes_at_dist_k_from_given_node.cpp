// Print all nodes at distance k from a given node
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

void print_nodes_down(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    print_nodes_down(root->left, k - 1);
    print_nodes_down(root->right, k - 1);
}

int printnodes(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        print_nodes_down(root, k);
        return 0;
    }
    int dl = printnodes(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_nodes_down(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printnodes(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            print_nodes_down(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
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
    printnodes(root, root->left->left, 2);
    cout << endl;
    printnodes(root, root->left->left, 3);
    return 0;
}