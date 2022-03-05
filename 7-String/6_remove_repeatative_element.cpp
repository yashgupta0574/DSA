#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // sort(s.begin(),s.end());
    int n = s.size(), i = 0;
    // for(int i=0;i<n;i++)
    while (i < n)
    {
        if (s[i + 1] == s[i])
        {
            s.erase(i, 1);
            n--;
        }
        else
        {
            i++;
        }
    }
    cout << s << endl;
    return 0;
}