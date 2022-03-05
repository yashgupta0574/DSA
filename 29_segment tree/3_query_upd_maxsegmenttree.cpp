#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
const int m = 1e9 + 7, N = 10;
int a[N], tree[4 * N];

void buildtree(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    buildtree(2 * node, st, mid);
    buildtree(2 * node + 1, mid + 1, en);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    return;
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return INT_MIN;
    }
    if (l <= st && r >= en)
    {
        return tree[node]; //complete segment
    }
    //partial segment
    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    return;
}

int main()
{
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    buildtree(1, 0, n - 1);
    while (1)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            break;
        }
        
        if (type == 1)
        {
            int l,r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
        
        else if (type == 2)
        {
            int idx,val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
            int ans = query(1, 0, n - 1, 0, n - 1);
            cout << ans << endl;
        }
    }
    return 0;
}
/*
9
6 8 -1 2 17 1 3 2 4
1
2 6
.......
2
7 18
*/