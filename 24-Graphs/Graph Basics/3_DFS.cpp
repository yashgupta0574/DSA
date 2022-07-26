// DFS stands for Depth First Search is a edge based technique.
// It uses the Stack data structure, performs two stages, first visited vertices are pushed into stack and
// second if there is no vertices then visited vertices are popped.
// Ex-

//         A
//        / \
//       B   C
//      /   / \
//     D   E   F
// Output is:

// A, B, D, C, E, F
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
bool vis[N];

void dfs(int top, vvi &adj)
{
    // preorder
    vis[top] = 1;
    cout << top << endl;

    // inorder
    vector<int>::iterator it;
    for (it = adj[top].begin(); it != adj[top].end(); it++)
    {
        if (!vis[*it])
            dfs(*it, adj);
    }

    // postorder
    // cout << top << endl;
    // uncomment line 43 and comment line 32 to get postorder
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, 0, n + 1)
    {
        vis[i] = 0;
    }
    dfs(1, adj);

    return 0;
}