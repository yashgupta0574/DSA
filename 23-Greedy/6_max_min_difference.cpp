//we have to divide array into two array of n/2 size then we have to compute max and min diff of elements for a[i] +b[i]
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
    int n;
    cin >> n;
    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    long long mx = 0, mn = 0;
    sort(v.begin(), v.end());
    rep(i, 0, n / 2)
    {
        mx += v[n / 2 + i] - v[i];
        mn += v[2 * i + 1] - v[2 * i];
    }
    cout << mx << endl;
    cout << mn << endl;

    return 0;
}