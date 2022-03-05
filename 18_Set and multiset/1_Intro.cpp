#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    s.erase(2);
    s.erase(s.begin());
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(10);
    ms.insert(5);
    ms.insert(7);
    ms.insert(7);
    ms.insert(7);
    ms.insert(7);
    ms.insert(7);
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << ms.size() << endl;
    ms.erase(2);
    ms.erase(ms.find(7));
    ms.erase(s.begin());
    for (auto i : ms)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}