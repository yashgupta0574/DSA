// It's like BFS traversal we traverse every node of BFS and check it's possibility
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
    vector<bool> vis(101, false);
    vis[1] = false;
    int snakes, ladders;
    map<int, int> snak;
    map<int, int> lad;
    cin >> ladders;

    rep(i, 0, ladders)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    cin >> snakes;
    rep(i, 0, snakes)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }
    int moves = 0;
    bool found = false;
    queue<int> q;
    q.push(1);
    while (!q.empty() && !found)
    {
        int sz = q.size();
        while (sz--)
        {
            int t = q.front();
            q.pop();
            rep(die, 1, 7) // die
            {
                if (t + die == 100)
                {
                    found = true;
                }
                else if (t + die <= 100 && lad[t + die] && !vis[lad[t + die]])
                {
                    vis[lad[t + die]] = true;
                    q.push(lad[t + die]);
                    if (lad[t + die] == 100)
                    {
                        found = true;
                    }
                }
                else if (t + die <= 100 && snak[t + die] && !vis[snak[t + die]])
                {
                    vis[snak[t + die]] == true;
                    q.push(snak[t + die]);
                }
                else if (t + die <= 100 && !vis[t + die] && !snak[t + die] && !lad[t + die])
                {
                    vis[t + die] == true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if (found)
    {
        cout << moves << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
/*
2
3 90
56 76
3
99 10
30 20
20 5
*/