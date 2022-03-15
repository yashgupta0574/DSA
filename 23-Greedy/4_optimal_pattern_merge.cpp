// #include <bits/stdc++.h>
// using namespace std;

// #define vi vector<int>
// #define pii pair<int, int>
// #define vii vector<pii>
// #define ff first
// #define ss second
// #define rep(i, a, b) for (int i = a; i < b; i++)

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     rep(i, 0, n) cin >> a[i];
//     priority_queue<int, vi, greater<int>> minheap;

//     rep(i, 0, n) minheap.push(a[i]);

//     while (minheap.size() > 1)
//     {
//         int x = minheap.top();
//         minheap.pop();
//         int y = minheap.top();
//         minheap.pop();
//         minheap.push(x + y);
//     }

//     cout << minheap.top() << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++)
    {
        minheap.push(a[i]);
    }
    int ans = 0;

    while (minheap.size() > 1)
    {
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}