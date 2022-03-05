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

void insertatHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void toDeleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int del)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        toDeleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != del)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
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
    node *head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatHead(head, 0);
    // deletion(head, 2);
    toDeleteAtHead(head);
    display(head);

    return 0;
}