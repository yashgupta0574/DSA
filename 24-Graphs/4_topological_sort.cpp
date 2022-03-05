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
    vvi adj(N);
    vi indegree(N, -1);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if (indegree[x] == -1)
        {
            indegree[x] = 0;
        }
        adj[x].push_back(y); //x->y
        indegree[y]++;
    }
    queue<int> pq;

    rep(i, 0, N)
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