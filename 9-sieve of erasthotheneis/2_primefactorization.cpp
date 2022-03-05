#include <iostream>
using namespace std;

void primefactors(int n)
{
    int a[n + 1] = {0};
    int spf[n + 1] = {0}; // spf = smallest prime factor
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    while (n > 1)
    {
        cout << spf[n] << endl;
        n = n / spf[n];
    }
}

int main()
{
    int n;
    cin >> n;
    primefactors(n);
    return 0;
}