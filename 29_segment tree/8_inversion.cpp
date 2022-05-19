// Present sir approach
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

int tree[4 * N], a[N];

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return 0;

    if (l <= st && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

signed main()
{
    for (int i = 0; i < 4 * N; i++)
    {
        tree[i] = 0;
    }

    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;

        int ans = query(1, 1, n, x, n);
        cout << ans << " ";
        update(1, 1, n, x, 1);
    }
    return 0;
}
