#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

class node
{
public:
    bool end;
    node *next[26];
    node()
    {
        rep(i, 0, 26)
        {
            next[i] = NULL;
            end = false;
        }
    }
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (it->next[c - 'a'] == NULL)
            {
                it->next[c - 'a'] = new node();
            }
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    void printall(node *it, string &s, vector<string> &res, string cur)
    {
        if (it == NULL)
        {
            return;
        }
        if (it->end)
        {
            res.push_back(cur);
        }
        rep(i, 0, 26)
        {
            if (it->next[i])
            {
                printall(it->next[i], s, res, cur + char('a' + i));
            }
        }
    }

    void find(string &s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (it->next[c - 'a'] == NULL)
            {
                cout << "No suggestions!" << endl;
                insert(s);
                return;
            }
            it = it->next[c - 'a'];
        }
        vector<string> res;
        printall(it, s, res, "");
        for (auto c : res)
        {
            cout << s << c << endl;
        }
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &i : a)
    {
        cin >> i;
        t.insert(i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        t.find(s);
    }
    return 0;
}