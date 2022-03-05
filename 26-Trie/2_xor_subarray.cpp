#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

class Trienode
{
public:
    Trienode *next[2];
    Trienode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

Trienode *buildtree(vector<int> &a)
{
    Trienode *root = new Trienode();
    int n = a.size();
    rep(i, 0, n)
    {
        int num = a[i];
        Trienode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (curr->next[bit] == NULL)
            {
                curr->next[bit] = new Trienode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}

int helper(Trienode *root, vector<int> &a)
{
    int res = 0;
    rep(i, 0, a.size())
    {
        int num = a[i];
        Trienode *it = root;
        int curr_max = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1) ? 0 : 1;
            if (it->next[bit])
            {
                curr_max <<=1;
                curr_max |= 1;
                it = it->next[bit];
            }
            else
            {
                curr_max <<= 1;
                it = it->next[bit xor 1];
            }
        }
        res = max(res, curr_max);
    }
    return res;
}

int main()
{
    vector<int> a = {3, 10, 5, 15, 2};
    Trienode *root = buildtree(a);
    cout << helper(root, a) << endl;
    return 0;
}