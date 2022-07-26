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

node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

node *searchinBST(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searchinBST(root->left, key);
    }
    return searchinBST(root->right, key);
}

node *inordersuccessor(node *root)
{
    struct node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteinBST(node *root, int key)
{

    if (key < root->data)
    {
        root->left = deleteinBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        struct node *temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
int main()
{
    struct node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    inorder(root);
    cout << endl;
    /*if (searchinBST(root, 5) != NULL)
    {
        cout << "Key found" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }*/
    root = deleteinBST(root, 5);
    inorder(root);
    cout << endl;
    return 0;
}