// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    vector<int> vis;
    stack<int> st;
    int ans = 0;
    void dfs(int i, vector<int> adj[])
    {
        int sz = adj[i].size();
        vis[i] = true;
        for (int j = 0; j < sz; j++)
        {
            if (!vis[adj[i][j]])
                dfs(adj[i][j], adj);
        }
        st.push(i);
    }

    void dfs1(int i, vector<int> tran[])
    {
        int sz = tran[i].size();
        vis[i] = true;
        for (int j = 0; j < sz; j++)
        {
            if (!vis[tran[i][j]])
                dfs1(tran[i][j], tran);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        vis = vector<int>(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, adj);
        }
        vis = vector<int>(V, false);
        vector<int> tran[V];
        for (int i = 0; i < V; i++)
        {
            int sz = adj[i].size();
            for (int j = 0; j < sz; j++)
                tran[adj[i][j]].push_back(i);
        }
        while (!st.empty())
        {
            int top = st.top();
            if (!vis[top])
            {
                ans++;
                dfs1(top, tran);
            }
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends