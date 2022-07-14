// Reverse of inversion question
// # Advanced version
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

int tree[4 * N], a[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int k)
{
    if (st == en)
    {
        return st;
    }

    int mid = (st + en) / 2;
    if (k < tree[2 * node])
    {
        return query(2 * node, st, mid, k);
    }
    else
    {
        return query(2 * node + 1, mid + 1, en, k - tree[2 * node]);
    }
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

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

signed main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        a[i] = 1;
    }

    build(1, 0, n - 1);

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int currPresentSirs = n;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int k = currPresentSirs - b[i] - 1; // No of presentsir just before the index(our required ans)
        cout << k << " ";
        currPresentSirs--;

        int temp = query(1, 0, n - 1, k);
        cout << temp << endl;
        update(1, 0, n - 1, temp, 0);
        ans.push_back(temp + 1);
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}