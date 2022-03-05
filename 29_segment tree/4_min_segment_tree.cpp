#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7, N = 10;
int a[N];
pii tree[4 * N];

void buildtree(int node, int st, int en)
{
    if (st == en)
    {
        tree[node].ff = a[st];
        tree[node].ss = 1;
        return;
    }
    int mid = (st + en) / 2;
    buildtree(2 * node, st, mid);
    buildtree(2 * node + 1, mid + 1, en);

    if (tree[2 * node].ff < tree[2 * node + 1].ff)
    {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss;
    }
    else if (tree[2 * node + 1].ff < tree[2 * node].ff)
    {
        tree[node].ff = tree[2 * node + 1].ff;
        tree[node].ss = tree[2 * node + 1].ss;
    }
    else //tree[2 * node + 1].ff == tree[2 * node].ff
    {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss + tree[2 * node].ss;
    }
    return;
}

pii query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return {MOD, -1};
    }
    if (l <= st && r >= en)
    {
        return tree[node]; //complete segment
    }
    //partial segment
    int mid = (st + en) / 2;
    pii q1 = query(2 * node, st, mid, l, r);
    pii q2 = query(2 * node + 1, mid + 1, en, l, r);
    pii q;
    if (q1.ff < q2.ff)
    {
        q = q1;
    }
    else if (q1.ff > q2.ff)
    {
        q = q2;
    }
    else
    {
        q.ff = q1.ff; //we can also write q=q2 as q1=q2
        q.ss = q1.ss + q2.ss;
    }
    return q;
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node].ff = val;
        tree[node].ss = 1;
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

    if (tree[2 * node].ff < tree[2 * node + 1].ff)
    {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss;
    }
    else if (tree[2 * node + 1].ff < tree[2 * node].ff)
    {
        tree[node].ff = tree[2 * node + 1].ff;
        tree[node].ss = tree[2 * node + 1].ss;
    }
    else //tree[2 * node + 1].ff == tree[2 * node].ff
    {
        tree[node].ff = tree[2 * node].ff;
        tree[node].ss = tree[2 * node].ss + tree[2 * node + 1].ss;
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    buildtree(1, 0, n - 1);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            //update
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }

        else if (type == 2)
        {
            //query
            int l, r;
            cin >> l >> r;
            pii ans = query(1, 0, n - 1, l, r);
            cout << ans.ff << " " << ans.ss << endl;
        }
    }
    return 0;
}
/*
5 5
3 4 3 5 2
2 0 3
1 1 2
2 0 3
1 0 2
2 0 5
*/