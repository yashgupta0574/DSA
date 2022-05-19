// Write a program to find a unique number in an array where all numbers except
// one, are present twice.
#include <iostream>
using namespace std;
int unique(int a[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ a[i];
    }
    return xorsum;
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
    cout << unique(a, n) << endl;
    return 0;
}