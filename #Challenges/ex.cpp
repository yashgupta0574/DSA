#include <bits/stdc++.h>
using namespace std;

int calc(string s)
{
    int x = 0, n = s.length() - 1, mult = 1;
    while (n != -1)
    {
        x += (s[n] - 48) * mult;
        // cout << x << " ";
        mult *= 10;
        n--;
    }
    return x;
}
int compareVersion(string version1, string version2)
{
    int ans = 0, a = version1.length(), b = version2.length(), i = 0, j = 0, n, m;
    string s1, s2;
    // cout << a << " " << b << " ";
    while (i <= a && j <= b)
    {
        s1 = "";
        s2 = "";
        // cout << s1 << s2 << "s1s2" << endl;
        while (i < a && version1[i] != '.')
        {
            s1 += version1[i];
            i++;
        }
        i++;
        n = calc(s1);
        // cout << version1[i - 1] << i << "n" << n << endl;
        while (j < b && version2[j] != '.')
        {
            s2 += version2[j];
            j++;
        }
        j++;
        m = calc(s2);
        // cout << version2[j - 1] << j << "m" << m << endl;
        if (n < m)
        {
            ans = -1;
            return ans;
        }
        if (n > m)
        {
            ans = 1;
            return ans;
        }
        // cout << i << j << " ij" << endl;
        //  cout << ans;
    }
    return ans;
}

int main()
{
    string s1 = "2.01.1";
    string s2 = "3.001.0";
    cout << compareVersion(s1, s2);
    return 0;
}