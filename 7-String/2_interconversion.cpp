#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "abcdefghij";
    // to upper case
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    cout << s << endl;

    // to lower case
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    cout << s << endl;
    return 0;
}
