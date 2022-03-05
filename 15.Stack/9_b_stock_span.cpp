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

void next_small(vector<int> &ng, int hist[])
{
    stack<int> st;
    for (int i = ng.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && hist[st.top()] <= hist[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ng[i] = ng.size();
        }
        else
        {
            ng[i] = st.top();
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

    vector<int> ng(n, 0);
    for (int i = 0; i < ng.size(); i++)
    {
        ng[i] = hist[i];
    }
    next_small(ng, hist);

    //****************************************//
    for (int i = 0; i < pg.size(); i++)
    {
        cout << pg[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ng.size(); i++)
    {
        cout << ng[i] << " ";
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