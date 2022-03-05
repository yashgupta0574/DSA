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

node *reverse_k_nodes(node *&head, int k)
{
    node *prev_ptr = NULL;
    node *curr_ptr = head;
    node *next_ptr;
    int count = 0;
    while (curr_ptr != NULL && count < k)
    {
        next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
        count++;
    }
    if (next_ptr != NULL)
    {
        head->next = reverse_k_nodes(next_ptr, k);
    }
    return prev_ptr;
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

    int k = 2;
    // int k=4;
    node *newhead = reverse_k_nodes(head, k);
    display(newhead);

    return 0;
}