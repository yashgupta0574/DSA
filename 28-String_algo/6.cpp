#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
const int m = 1e9 + 7, N = 1e2;
int p = 31; // we can take p any number > 26
vector<long long> powers(N);

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int ans1 = 0, cmp = -1, n = tops.size(), ans2 = 0, minm1 = INT_MAX, minm2 = INT_MAX;
    if (tops[0] == bottoms[1])
    {
        cmp = tops[0];
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != cmp)
                ans1++;
        }
        for (int i = 0; i < n; i++)
        {
            if (bottoms[i] != cmp)
                ans2++;
        }
        minm1 = min(ans1, ans2);
    }
    // else if(tops[0]==bottoms[1]) cmp=tops[0];
    else if (bottoms[0] == tops[1])
    {
        cmp = bottoms[0];
        ans1 = 0;
        ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (bottoms[i] != cmp)
                ans1++;
        }
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != cmp)
                ans2++;
        }
        minm2 = min(ans1, ans2);
    }
    // else if(tops[1]==bottoms[1]) cmp=tops[1];
    else
        return -1;
    // cout<<cmp<<endl;
    return min(minm1, minm2);
}

int32_t main()
{

    return 0;
}