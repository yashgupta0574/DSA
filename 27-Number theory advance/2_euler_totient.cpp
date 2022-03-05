#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    int totient[n + 1];
    rep(i, 0, n + 1)
    {
        totient[i] = i;
    }
    rep(i, 2, n + 1)
    {
        if (totient[i] == i)
        {
            for (int j = 2 * i; j <= n + 1; j += i)
            {
                totient[j] *= (i - 1);
                totient[j] /= i;
            }
            totient[i] = i - 1; //here i will be prime so num from 1tp i-1 will be totient
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << totient[i] << " ";
    }
    return 0;
}