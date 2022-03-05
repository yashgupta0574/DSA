// record breaker
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    int count = 0, mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx && a[i] > a[i + 1])
        {
            count++;
        }
        mx = max(mx, a[i]);
    }
    cout << count;
    return 0;
}