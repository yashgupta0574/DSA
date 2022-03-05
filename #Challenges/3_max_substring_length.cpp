// max substring length without repetiting characters
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> v(256, 0);
    int start = -1, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (v[s[i]] > start)
        {
            // start = v[s[i]];
            start = i;
        }
        v[s[i]] = i;
        ans = max(ans, i - start + 1);
    }
    cout << ans << endl;
    return 0;
}