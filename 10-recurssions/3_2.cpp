// move all x to end of string
#include <iostream>
using namespace std;

string moveallx(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string str = moveallx(s.substr(1));
    if (ch == 'x')
    {
        return (str + ch);
    }
    return (ch + str);
}

int main()
{
    string s;
    cin >> s;
    cout << moveallx(s) << endl;
}