// REMEMBER: We cannot find Cycle in directed graphs using DSU
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
int N = 1e5 + 6;
vi parent;
vi sz; // sz=size
bool cycle;

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a); // union is always done of the leaders of their respective sets
    b = find_set(b); // union is always done of the leaders of their respective sets
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    parent = vi(n);
    sz = vi(n);
    cycle = false;
    vvi edges;

    rep(i, 0, n)
    {
        make_set(i);
    }

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            cycle = true;
        }
        else
        {
            union_set(u, v);
        }
    }

    if (cycle)
    {
        cout << "Graph has cycle" << endl;
    }
    else
    {
        cout << "Graph does not have cycle" << endl;
    }
    return 0;
}