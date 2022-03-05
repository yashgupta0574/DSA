#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    int sum = 0, cnt = 0;
    priority_queue<int, vi> pqmax;
    rep(i, 0, n)
    {
        pqmax.push(a[i]);
    }
    while (!pqmax.empty())
    {
        sum += pqmax.top();
        cnt++;
        pqmax.pop();
        if (sum >= k)
        {
            break;
        }
    }
    if (sum < k)
    {
        cnt = -1;
        cout << "Not found" << endl;
    }
    cout << cnt << endl;
    return 0;
}