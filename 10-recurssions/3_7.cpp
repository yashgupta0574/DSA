#include <iostream>
using namespace std;

void keypad(string s, string ans)
{
    string keypadarr[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuvw", "xyz"};
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string code = keypadarr[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    keypad(s, "");
}