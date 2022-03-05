// remove duplicates
#include <iostream>
using namespace std;

string removeduplicates(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string str = removeduplicates(s.substr(1));
    if (ch == str[0])
    {
        return (str);
    }
    return (ch + str);
}

int main()
{
    string s;
    cin >> s;
    cout << removeduplicates(s) << endl;
}