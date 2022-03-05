#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

class Trie
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            rep(i, 0, 26)
            {
                next[i] = NULL;
            }
        }
    };

    node *trie;
    Trie()
    {
        trie = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word)
    {
        int i = 0;
        node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Trie *mytrie = new Trie();
    vector<string> words = {"yash", "xyz"};
    for (auto w : words)
    {
        mytrie->insert(w);
    }
    if (mytrie->search("abcd"))
    {
        cout << "abcd found" << endl;
    }
    else
    {
        cout << "abcd not found" << endl;
    }
    if (mytrie->search("yash"))
    {
        cout << "yash found" << endl;
    }
    else
    {
        cout << "yash not found" << endl;
    }
    return 0;
}