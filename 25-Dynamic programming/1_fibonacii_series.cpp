#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e2 + 2;

int dp[N];

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main()
{
    // memoization{top to bottom}
    /*int n;
    cin >> n;
    rep(i, 0, n + 1)
    {
        dp[i] = -1;
    }
    cout << fib(n) << endl;*/

    // tabulation(bottom up method)
    int n;
    cin >> n;
    vi fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    rep(i, 3, n + 1)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout << fib[n] << endl;
    return 0;
}
