// Given a nxm matrix.
// Write an algorithm to find that the given value exists in the matrix or not.
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
#include <iostream>
using namespace std;

int main()
{
    int n, m, target;
    cin >> n >> m >> target;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bool flag = 0;
    int r = 0, c = m - 1;
    while (c >= 0 && r < m)
    {
        if (a[r][c] == target)
        {
            flag = 1;
            cout << r << " " << c << endl;
            break;
        }
        else if (a[r][c] < target)
        {
            r++;
        }
        else
        {
            c--;
        }
    }
    if (flag)
    {
        cout << "Element found";
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}