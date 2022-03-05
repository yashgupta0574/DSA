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
int a[N], tree[4 *N];

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

int main()
{
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    buildtree(1, 0, n - 1);
    rep(i, 1, 15)
    {
        cout << tree[i] << endl;
    }

    return 0;
}