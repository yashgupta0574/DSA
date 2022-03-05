#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertatHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertatTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertatHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void toDeleteAtHead(node *&head)
{
    cout << "delete at head" << endl;
    node *todelete = head;
    head = head->next;
    head->next->prev = NULL;
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
    if (temp->next != NULL)
    {
        temp->next->prev = temp;
    }
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
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    display(head);
    // insertatHead(head, 0);
    // display(head);
    deletion(head, 6);
    display(head);

    return 0;
}