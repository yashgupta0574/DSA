// You are given a string s consisting of lowercase letters latin letters (‘a’ to ‘z’) and
// some ‘?’. Your task is to find the number of subsequences ‘abc’ in all the strings.
//‘?’ should be replaced by either of {‘a’, ‘b’, ‘c’}.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
const int N = 1e2 + 2, MOD = 1e9 + 1;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int e = 1, a = 0, ab = 0, abc = 0;
    rep(i, 0, n)
    {
        if (s[i] == 'a')
        {
            a += e;
        }
        else if (s[i] == 'b')
        {
            ab += a;
        }
        else if (s[i] == 'c')
        {
            abc += ab;
        }
        else if (s[i] == '?')
        {
            abc = 3 * abc + ab;
            ab = 3 * ab + a;
            a = 3 * a + e;
            e = 3 * e;
        }
        else
        {
            cout << "Enter valid character in string either a,b,c,?" << endl;
        }
    }
    cout << abc << endl;
    return 0;
}
