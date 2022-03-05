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

int sum_kth_level(node *root, int n)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int ans = 0, level = 0;
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (curr != NULL)
        {
            if (level == n)
            {
                ans += curr->data;
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return ans;
}

int main()
{
    int k;
    cin >> k;
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << sum_kth_level(root, k);

    return 0;
}