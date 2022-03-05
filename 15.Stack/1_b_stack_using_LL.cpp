#include <iostream>
using namespace std;

class stack
{
public:
    int data;
    stack *next;
    stack(int val)
    {
        data = val;
        next = NULL;
    }
};

int n;
int count;

void push(stack *&head, int val)
{
    if (count == n)
    {
        cout << "Stack overflow" << endl;
        return;
    }
    stack *n = new stack(val);
    n->next = head;
    head = n;
    count++;
}

void pop(stack *&head)
{
    if (!count)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    stack *temp;
    temp = head->next;
    free(head);
    head = temp;
    count--;
}

void top(stack *head)
{
    if (!count)
    {
        cout << "Empty!!!!!" << endl;
        return;
    }
    if (count)
    {
        cout << "Stack is empty" << endl;
    }
    cout << head->data << endl;
}

bool isempty()
{
    return count == 0;
}

void display(stack *head)
{
    stack *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    stack *head = NULL;
    cin >> n;
    count = 0;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    display(head);
    top(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    top(head);
    if (isempty())
    {
        cout << "Stack is empty" << endl;
    }
    display(head);

    return 0;
}