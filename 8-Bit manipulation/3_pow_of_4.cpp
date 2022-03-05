#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = 0;
    if (__builtin_popcount(n) == 1)
    {
        for (int i = 2; i <= 31; i = i + 2)
        {
            if ((1 << i) == n)
            {
                flag = 1;
            }
        }
    }
    if (flag)
    {
        cout << "no is pow of 4" << endl;
    }
    else
    {
        cout << "no is not pow of 4" << endl;
    }
    return 0;
}