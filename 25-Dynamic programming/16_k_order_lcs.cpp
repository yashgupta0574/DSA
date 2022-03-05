//we can change any k particular elements of any one array to make more elements in common subsequence
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int dp[10][10][7];
int n, m, k;
vector<int> a, b;

int solve(int i, int j, int k)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    int c1 = 0, c2 = 0, c3 = 0;
    if (a[i] == b[j])
    {
        c1 = 1 + solve(i + 1, j + 1, k);
    }
    if (k > 0)
    {
        c2 = 1 + solve(i + 1, j + 1, k - 1); //man le ki humne change kar diya particular element to make it equal with other arr element
    }
    c3 = max(solve(i + 1, j, k), solve(i, j + 1, k));
    return dp[i][j][k] = max({c1, c2, c3});
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    a = vector<int>(n);
    b = vector<int>(m);
    for (auto &i : a)
    {
        cin >> i;
    }
    for (auto &i : b)
    {
        cin >> i;
    }
    cout << solve(0, 0, k) << endl;

    return 0;
}
/*
5 5 1
1 2 3 4 5
5 3 1 4 2
*/