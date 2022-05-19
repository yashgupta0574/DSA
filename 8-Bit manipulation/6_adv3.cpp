// Write a program to find a unique number in an array where all numbers
// except one, are present thrice.
#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int setbit(int n, int pos)
{
    return (n | (1 << pos));
}

int unique(int a[], int n)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(a[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setbit(result, i);
        }
    }
    return result;
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