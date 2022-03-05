//minimum spanning tree
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
vi sz; //sz=size

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
    a = find_set(a); //union hamesha leaders ka hota h
    b = find_set(b); //union hamesha leaders ka hota h
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
    parent = vi(n+1);
    sz = vi(n+1);
    vvi edges;
    int cost = 0;
    rep(i, 0, n)
    {
        make_set(i);
    }
    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    } 
    sort(edges.begin(), edges.end());
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            //cycle = true;
            continue; //because we don't want cycle
        }
        else
        {
            cout << u << " " << v << endl;
            cost += w;
            union_set(u, v);
        }
    }
    cout << "Cost is: " << cost << endl;
    return 0;
}
/*
8 9
1 2 5
2 3 6
4 3 2
1 4 9  
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1*/