#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> bit;

void update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

int query(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += bit[idx];
        idx = idx - (idx & (-idx));
    }
    return ans;
}

signed main()
{
    cin >> n;
    bit = vector<int>(n + 1, 0);
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }
    int inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        inv += query(a[i] - 1);
        update(a[i], 1);
    }
    cout << inv << endl;
    return 0;
}