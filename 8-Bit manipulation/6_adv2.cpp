// Write a program to find 2 unique numbers in an array where all numbers
// except two, are present twice.
#include <iostream>
using namespace std;

int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int a[], int n)
{
    int xorsum = 0, position = 0, unique1 = 0, unique2;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ a[i];
    }
    for (int i = 0; i < 32; i++)
    {
        if (getbit(xorsum, i))
        {
            position = i;
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (getbit(a[j], position))
        {
            unique1 = xorsum ^ a[j];
        }
    }
    unique2 = xorsum ^ unique1;
    cout << unique1 << endl
         << unique2 << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unique(a, n);
    return 0;
}