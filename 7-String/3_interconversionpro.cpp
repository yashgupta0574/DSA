#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    // to upper case
    sort(s.begin(), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    // to lower
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
}