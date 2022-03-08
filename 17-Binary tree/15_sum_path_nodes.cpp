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

int calc_sum(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = calc_sum(root->left, ans);
    int r = calc_sum(root->right, ans);
    int singlepathsum = max(root->data, max(root->data + l, root->data + r));
    int allpathsum_max = max(singlepathsum, root->data + l + r);
    ans = max(allpathsum_max, ans);
    return singlepathsum;
}

int maxpathsum(node *root)
{
    int ans = INT_MIN;
    calc_sum(root, ans);
    return ans;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(-3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << maxpathsum(root) << endl;
    return 0;
}