#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int coef = 1;
    for (int i = 0; i < n; i++)
    {
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
            {
                cout << coef << " ";
            }
            else
            {
                coef = coef * (i - j + 1) / j;
                cout << coef << " ";
            }
        }

        cout << endl;
    }
    return 0;
}