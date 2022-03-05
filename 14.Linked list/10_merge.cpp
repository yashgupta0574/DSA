#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertatTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *merge(node *&head1, node *&head2) // iterative
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummynode = new node(-1);
    node *ptr3 = dummynode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    if (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummynode->next;
    delete ptr1;
    delete ptr2;
}

node *mergeRecursive(node *&head1, node *&head2) // recursive
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int n, m, pos;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        insertatTail(head1, arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        insertatTail(head2, arr2[i]);
    }
    display(head1);
    display(head2);
    node *newhead = merge(head1, head2);
    // node *newhead = mergeRecursive(head1, head2);
    display(newhead);

    return 0;
}