// BFS stands for Breadth First Search is a vertex based technique for finding a shortest path in graph.
// It uses a Queue data structure which follows first in first out.
// In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue.
// It is slower than DFS.
// Ex-
//         A
//        / \
//       B   C
//      /   / \
//     D   E   F
// Output is:
// A, B, C, D, E, F

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5 + 2, MOD = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vi adj[n + 1]; // It is 2d array if adj(n) then 1d array
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool vis[n + 1];
    rep(i, 0, n + 1)
        vis[i] = 0;

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << endl;
        vector<int>::iterator it;
        for (it = adj[top].begin(); it != adj[top].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }

    return 0;
}