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
        idx -= (idx & (-idx));
    }
    return ans;
}

signed main()
{
    cin >> n;
    bit = vector<int>(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1) // query
        {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            ans = query(r) - query(l - 1);
            cout << ans << endl;
        }
        else if (type == 2) // update
        {
            int idx, val;
            cin >> idx >> val;
            update(idx, val - a[idx]); // final=a[idx]+val-a[idx]=val
            a[idx] = val;
        }
    }

    return 0;
}