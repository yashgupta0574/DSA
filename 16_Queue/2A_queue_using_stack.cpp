//#include <bits/stdc++.h>
// without using function call stack
#include <iostream>
#include <stack>
using namespace std;

class que
{
    stack<int> s1;
    stack<int> s2;

public:
    void enque(int x)
    {
        s1.push(x);
    }
    int deque()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool Empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    que q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    cout << q.deque() << endl;
    q.enque(5);

    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    cout << q.Empty() << endl;

    return 0;
}