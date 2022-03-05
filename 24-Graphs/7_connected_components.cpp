#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
vector<bool> vis;
vvi adj;

int get_comp(int idx)
{
    if (vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vvi(n);
    vis = vector<bool>(n, 0);
    vi components;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, 0, n)
    {
        if (!vis[i])
        {
            components.push_back(get_comp(i));
        }
    }
    for (auto i : components)
    {
        cout << i << " ";
    }

    return 0;
}