#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int m = 1e9 + 7, N = 1e2;
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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return 0;
    }
    if (l <= st && r >= en)
    {
        return tree[node]; // complete segment
    }
    // partial segment
    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
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
        cin >> type; // type any number >0 to continue searching result
        if (type < 0)
        {
            break;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
    }
    return 0;
}
/*8
5 3 2 4 1 8 6 10
*/