// Valid for all Directed,Undirected,weighted and unweighted
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int inf = 1e5;
int main()
{
    vector<vi> graph = {
        {0, 5, inf, 10},
        {inf, 0, 3, inf},
        {inf, inf, 0, 1},
        {inf, inf, inf, 0}};
    int n = graph.size();
    vvi dist = graph;
    rep(k, 0, n)
    {
        rep(i, 0, n)
        {
            rep(j, 0, n)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (dist[i][j] == inf)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}