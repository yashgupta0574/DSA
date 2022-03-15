// example of backtracking
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

void printsudoku(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool issafe(int grid[9][9], int row, int col, int num)
{
    for (int i = 0; i <= 8; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i <= 8; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    int rowstart = row - row % 3;
    int colstart = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowstart][j + colstart] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solvesudoku(int grid[9][9], int row, int col)
{
    if (row == 8 && col == 9)
    {
        return true;
    }
    if (col == 9)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
    {
        return solvesudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= 9; num++)
    {
        if (issafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solvesudoku(grid, row, col + 1))
            {
                return true;
            }
        }

        grid[row][col] = 0; // backtracking, since function called for col+1 doesn't return true
    }
    return false;
}

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solvesudoku(grid, 0, 0))
    {
        printsudoku(grid);
    }
    else
    {
        cout << "No solution" << endl;
    }
    return 0;
}