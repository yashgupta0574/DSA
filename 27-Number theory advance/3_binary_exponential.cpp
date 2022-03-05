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

int poweriterative(int a, int n)
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

int powerrecursive(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int ans;
    int p = powerrecursive(a, n / 2);
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
    //cout << poweriterative(a, n) << endl;//iterarive
    cout << powerrecursive(a, n) << endl;
    return 0;
}