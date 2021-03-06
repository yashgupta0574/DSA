// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of
// vertices such that for every directed edge u v, vertex u comes before v in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG.
// There can be more than one topological sorting for a graph.
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e5 + 2;

int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    vi indegree(n + 1, 0);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // x->y
        indegree[y]++;
    }
    queue<int> pq;

    rep(i, 0, n)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for (auto it : adj[x])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                pq.push(it);
            }
        }
    }

    return 0;
}
//
// 6 6
// 5 0
// 4 0
// 5 2
// 2 3
// 3 1
// 4 1