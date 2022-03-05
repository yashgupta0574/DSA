#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 'a']++;
    }
    char ans;
    int maxfreq = -1;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] > maxfreq)
        {
            maxfreq = a[i];
            ans = i + 'a';
        }
    }
    cout << maxfreq << endl
         << ans << endl;
    return 0;
}