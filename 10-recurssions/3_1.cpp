#include <iostream>
using namespace std;

void reverse(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    string rev = s.substr(1);
    reverse(rev);
    cout << s[0];
}

int main()
{
    string s;
    cin >> s;
    reverse(s);
}
