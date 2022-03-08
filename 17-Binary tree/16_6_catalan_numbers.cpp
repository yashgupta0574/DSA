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

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

// catalan number application

vector<node *> buildtree(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftsubtrees = buildtree(start, i - 1);
        vector<node *> rightsubtrees = buildtree(i + 1, end);

        for (int j = 0; j < leftsubtrees.size(); j++)
        {
            node *left = leftsubtrees[j];
            for (int k = 0; k < rightsubtrees.size(); k++)
            {
                node *right = rightsubtrees[k];
                node *root = new node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
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
    /*for (int i = 0; i <= 10; i++)
    {
        cout << catalan(i) << endl;
    }*/

    vector<node *> maketree = buildtree(1, 3);
    for (int i = 0; i < maketree.size(); i++)
    {
        preorder(maketree[i]);
        cout << endl;
    }
    return 0;
}