#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int orignum = n;
    int sum = 0;
    int rem;
    while (n > 0)
    {
        rem = n % 10;
        sum += rem * rem * rem;
        n = n / 10;
    }

    if (sum == orignum)
    {
        cout << "armstrong number" << endl;
    }
    else
    {
        cout << "non-armstrong number" << endl;
    }

    return 0;
}