// application of Fermat little and wilson theorem
// to find: n! mod p where p is prime and n is integer
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int powerIterative(int i, int x, int p) // i^x
{
    int ans = 1;
    i = i % p;
    while (x > 0)
    {
        if (x & 1)
        {
            ans = (ans * i) % p;
        }
        i = (i * i) % p;
        x = x >> 1;
    }
    return ans;
}

int calculateModuloInverse(int i, int p)
{
    return powerIterative(i, p - 2, p);
}

int calculateModulo(int n, int p)
{
    if (p < n)
    {
        return 0;
    }
    int res = p - 1; // wilson theorem
    rep(i, n + 1, p)
    {
        res = (res * calculateModuloInverse(i, p)) % p;
    }
    return res;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << calculateModulo(n, p) << endl;
    return 0;
}