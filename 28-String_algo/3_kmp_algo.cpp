#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

void computeLps(string t, int m, vi lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps=longest prefix which is same as suffix
    while (i < m)
    {
        if (t[i] == t[len])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    string s = "wow";
    string t = "ohh wow u are so smart wow";
    int n = s.size();
    int m = t.size();
    vi lps(m + 1, 0);
    computeLps(t, m, lps);
    int i = 0, j = 0;
    while (i < m)
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == n)
        {
            cout << i - j << endl;
            j = lps[j - 1];
        }
    }
    return 0;
}