#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void insert(int x)
{
    if (pqmin.size() == pqmax.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }
        else
        {
            if (x < pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                pqmin.push(x);
            }
            return;
        }
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            if (x >= pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findmedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else if (pqmin.size() > pqmax.size())
    {
        return pqmin.top();
    }
    else
    {
        return pqmax.top();
    }
}

int main()
{
    insert(10);
    cout << findmedian() << endl;
    insert(20);
    cout << findmedian() << endl;
    insert(25);
    cout << findmedian() << endl;
    insert(40);
    cout << findmedian() << endl;
    return 0;
}