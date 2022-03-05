// spiral printing of elements of matrix
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
    while (row_start <= row_end && column_start <= column_end)
    {

        for (int k = column_start; k <= column_end; k++)
        {
            cout << a[row_start][k] << " ";
        }
        row_start++;

        for (int k = row_start; k <= row_end; k++)
        {
            cout << a[k][column_end] << " ";
        }
        column_end--;

        for (int k = column_end; k >= column_start; k--)
        {
            cout << a[row_end][k] << " ";
        }
        row_end--;

        for (int k = row_end; k >= row_start; k--)
        {
            cout << a[k][column_start] << " ";
        }
        column_start++;
    }
    return 0;
}