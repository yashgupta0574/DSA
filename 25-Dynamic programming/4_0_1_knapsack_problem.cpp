#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e2 + 2, MOD = 1e9 + 1;

//int dp[N][N];
vi val, wt;

/*int knapsack(int n, int w)
{
    if (w <= 0)
    {
        return 0;
    }
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] > w)
    {
        return knapsack(n - 1, w);
    }
    else
    {
        dp[n][w] = max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
    }
    return dp[n][w];
}*/

int main()
{
    //memoization
    /*int n;
    cin >> n;
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            dp[i][j] = -1;
        }
    }
    wt = vi(n);
    rep(i, 0, n)
    {
        cin >> wt[i];
    }
    val = vi(n);
    rep(i, 0, n)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;
    cout << knapsack(n, w) << endl;*/

    //iterative
    int n;
    cin >> n;
    wt = vi(n + 1);
    rep(i, 0, n)
    {
        cin >> wt[i];
    }
    val = vi(n + 1);
    rep(i, 0, n)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;
    vvi dp(n + 1, vi(w + 1, 0));
    rep(i, 1, n + 1)
    {
        rep(j, 0, w + 1)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
/*
3
15 30 45
60 100 150
50
*/