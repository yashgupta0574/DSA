#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

int powerIterative(int a, int n)
{
    int ans = 1;
    a = a % MOD;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return ans;
}

int powerRecursive(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans;
    int p = powerRecursive(a, n / 2);
    if (n % 2 == 0)
    {
        return ans = p * p;
    }
    else
    {
        return ans = p * p * a;
    }
}

int main()
{
    int a, n;
    cin >> a >> n;
    // cout << powerIterative(a, n) << endl;//iterarive
    cout << powerRecursive(a, n) << endl;
    return 0;
}