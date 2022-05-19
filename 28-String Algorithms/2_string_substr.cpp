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

int main()
{
    string s = "ya";
    string t = "yupp, ya how r y ya";
    int S = s.size(), T = t.size();
    rep(i, 0, T - S + 1)
    {
        if (t.substr(i, S) == s)
        {
            cout << "Found at: " << i << endl;
        }
    }
    // time complexity=O(ST);
    return 0;
}