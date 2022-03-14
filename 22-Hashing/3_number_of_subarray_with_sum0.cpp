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
    int n, prefsum = 0, ans = 0;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    map<int, int> m;
    rep(i, 0, n)
    {
        prefsum += a[i];
        m[prefsum]++;
    }
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        int x = it->ss, y = it->ff;
        if (y != 0)
            ans += x * (x - 1) / 2;
        else if (y == 0)
            ans += x;
    }
    cout << ans << endl;
    return 0;
}