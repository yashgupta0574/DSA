#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int m = 1e9 + 7, N = 1e2;
int p = 31; //we can take p any number > 26

vector<long long> powers(N);

int calculate_hashes(string s)
{
    int hash = 0;
    rep(i, 0, s.size())
    {
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % m;
    }
    return hash;
}

int main()
{
    powers[0] = 1;
    rep(i, 1, N)
    {
        powers[i] = (powers[i - 1] * p) % m;
    }
    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "aa"};
    vector<long long> hashes;
    for (auto w : strings)
    {
        hashes.push_back(calculate_hashes(w));
    }
    int distinct = 0;
    sort(hashes.begin(), hashes.end());
    rep(i, 0, hashes.size())
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
        {
            distinct++;
        }
    }
    cout << distinct << endl;
    return 0;
}