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

int height(node *newroot)
{
    if (newroot == NULL)
    {
        return 0;
    }
    return max(height(newroot->left), height(newroot->right)) + 1;
}
int diameter(node *root) // O(n^2)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdia = lheight + rheight + 1;
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    int ans = max(currdia, max(ldiameter, rdiameter));
    return ans;
}

//******************************* VVVIMP***********************************
int Diameter(node *root, int *height) // O(n) Simultaneously calculates height too
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = Diameter(root->left, &lh);
    int rdiameter = Diameter(root->right, &rh);
    int currdia = lh + rh;
    *height = max(lh, rh) + 1;
    return max(currdia, max(ldiameter, rdiameter));
}
//*************************VVVIMP*******************************************

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int height = 0;
    cout << diameter(root) << endl;
    cout << Diameter(root, &height) << endl;
    cout << height << endl;
    return 0;
}