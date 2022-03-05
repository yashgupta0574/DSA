// to check palindrome
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    int n;
    cin >> n;
    char a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool check = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - 1 - i])
        {
            check = 0;
        }
    }
    if (check)
    {
        cout << a << " is an palindrome.";
    }
    else
    {
        cout << a << " is not an palindrome.";
    }
    return 0;
}