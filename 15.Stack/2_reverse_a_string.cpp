#include <iostream>
#include <stack>
using namespace std;

void reversestring(string s)
{
    stack<string> st;
    int i = 0;
    while (i < s.length())
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
        i++;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "Hey, how are you doing?";
    reversestring(s);

    return 0;
}