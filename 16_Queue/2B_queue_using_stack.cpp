// with using function call stack
#include <iostream>
#include <stack>
using namespace std;

class que
{
    stack<int> s1;

public:
    void enque(int x)
    {
        s1.push(x);
    }
    int deque()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int topop = deque();
        s1.push(x);
        return topop;
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