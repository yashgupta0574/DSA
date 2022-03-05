#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    priority_queue<int, vector<int>, greater<int>> pqmin; // min heap is formed greater int will convert max heap into min heap
    // because only max heap can be formed
    pqmin.push(5);
    pqmin.push(10);
    pqmin.push(9);
    pqmin.push(1);
    pqmin.push(15);
    cout << pqmin.top() << endl;
    pqmin.pop();
    cout << pqmin.top() << endl;
    return 0;
}