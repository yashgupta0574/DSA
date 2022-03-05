#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node(int value)
    {
        val = value;
        next = NULL;
    }
};

node *sortList(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    node *temp1 = head->next;
    while (temp->next != NULL)
    {
        temp1 = temp->next;
        while (temp1 != NULL)
        {
            if (temp1->val < temp->val)
            {
                // swap(temp->val,temp1->val);
                int x = temp->val;
                temp->val = temp1->val;
                temp1->val = x;
                cout << temp->val << " " << temp1->val << endl;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    return head;
}

void insertatTail(node *&head, int value)
{
    node *n = new node(value);
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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertatTail(head, 4);
    insertatTail(head, 2);
    insertatTail(head, 1);
    insertatTail(head, 3);
    node *temp = sortList(head);
    display(temp);
    return 0;
}