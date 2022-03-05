// to find largest word and it's length
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100] = "apple";
    int n;
    cin >> n;
    cin.ignore();
    cin.getline(a, n);
    cin.ignore();
    int i = 0;
    int st = 0, maxst = 0;
    int currensum = 0;
    int maxsum = 0;
    while (i < n)
    {
        if (a[i] == ' ' || a[i] == '\0')
        {
            if (currensum > maxsum)
            {
                maxsum = currensum;
                maxst = st;
            }
            st = i + 1;
            currensum = 0;
        }
        else
        {
            currensum++;
        }
        if (a[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << a << endl;
    cout << maxsum << endl;
    for (int i = 0; i < maxsum; i++)
    {
        cout << a[maxst + i];
    }
    cout << endl;

    return 0;
}