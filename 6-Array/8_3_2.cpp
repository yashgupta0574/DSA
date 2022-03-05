// Bubble sort
#include <iostream>
using namespace std;

int main()
{
    int n, key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int counter = 1;
    for (int i = 1; i < n - 1; i++)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        counter += 1;
    }
    for (int k = 0; k < n; k++)
    {
        cout << a[k] << " ";
    }
    return 0;
}