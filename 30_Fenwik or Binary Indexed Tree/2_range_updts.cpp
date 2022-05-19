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
        cout<<idx<<endl;
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
    int u;
    cin >> u;
    while (u--)
    {
        int l, r, inc;
        cin >> l >> r >> inc;
        update(l, inc);
        update(r + 1, -inc);
    }
    int v;
    cin >> v;
    while (v--)
    {
        int idx;
        cin >> idx;
        cout << query(idx) << endl;
    }
    cout<<bit[5]<<endl;
    return 0;
}