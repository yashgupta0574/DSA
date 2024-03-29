#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

void computeLps(string pat, int m, vi &lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps is longest proper prefix which is same as suffix
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len != 0) len = lps[len - 1];
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
    string txt = "I am rated 4 stars at codechef and having max rating of 1326 on codeforces";
    string pat = "star";
    int n = txt.size();
    int m = pat.size();
    vi lps(m + 1, 0);
    computeLps(pat, m, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
        if (j == m)
        {
            cout << i - j << endl;
            j = lps[j - 1];
        }
    }
    return 0;
}