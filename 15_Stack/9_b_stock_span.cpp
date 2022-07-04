#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void prev_great(vector<int> &pg, int hist[])
{
    stack<int> st;
    for (int i = 0; i < pg.size(); i++)
    {
        while (!st.empty() && hist[st.top()] <= hist[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pg[i] = -1;
        }
        else
        {
            pg[i] = st.top();
        }
        st.push(i);
    }
}

void stockSpan(int hist[], int n)
{
    vector<int> pg(n, 0);
    for (int i = 0; i < pg.size(); i++)
    {
        pg[i] = hist[i];
    }
    prev_great(pg, hist);
    //****************************************//
    for (int i = 0; i < pg.size(); i++)
    {
        cout << pg[i] << " ";
    }
    cout << endl;

    //****************************************//
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = i - pg[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int hist[] = {1, 2, 2, 6, 7, 4, 5, 3, 2};
    int n = sizeof(hist) / sizeof(hist[0]);
    stockSpan(hist, n);
    return 0;
}