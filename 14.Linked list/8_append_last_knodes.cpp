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

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *append_last_k_nodes(node *&head, int k)
{
    node *new_head;
    node *new_tail;
    node *temp = head;
    int l = length(head);
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == (l - k))
        {
            new_tail = temp;
        }
        if (count == (l - k + 1))
        {
            new_head = temp;
        }
        temp = temp->next;
        count++;
    }
    new_tail->next = NULL;
    temp->next = head;
    return new_head;
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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        insertatTail(head, arr[i]);
    }
    /*insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);*/
    display(head);

    int k = 3;
    node *newhead = append_last_k_nodes(head, k);
    display(newhead);

    return 0;
}