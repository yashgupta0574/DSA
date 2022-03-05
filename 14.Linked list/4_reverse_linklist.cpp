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

node *reverseIterative(node *&head)
{
    node *prev_ptr = NULL;
    node *curr_ptr = head;
    node *next_ptr;
    while (curr_ptr != NULL)
    {
        next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    return prev_ptr;
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
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
    display(head);
    // node *newhead = reverseIterative(head);
    node *newhead = reverseRecursive(head);
    display(newhead);

    return 0;
}