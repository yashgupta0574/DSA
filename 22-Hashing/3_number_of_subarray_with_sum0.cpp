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
    m[0] = 1;
    rep(i, 0, n)
    {
        prefsum += a[i];
        ans += m[prefsum];
        m[prefsum]++;
    }
    cout << ans << endl;
    return 0;
}