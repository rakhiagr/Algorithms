#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;

class Trie
{
public:
    Trie *node[26];
    // bool ended;

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            node[i] = NULL;
        }
        // ended = false;
    }
};

Trie *root;

void insert(string s)
{
    Trie *cur = root;

    for (int i = 0; i < s.size(); i++)
    {
        if (!cur->node[s[i] - 'a'])
        {
            cur->node[s[i] - 'a'] = new Trie();
        }
        cur = cur->node[s[i] - 'a'];
    }
    // cur->ended = true;
}

bool checkInTrie(string s)
{
    Trie *cur = root;

    for (int i = 0; i < s.size(); i++)
    {
        if (cur->node[s[i] - 'a'] == NULL)
            return false;
        cur = cur->node[s[i] - 'a'];
    }
    // return cur->ended;
    return true;
}

int32_t main()
{
    root = new Trie();
    insert("himanshu");
    insert("himu");
    insert("shubhanshu");
    insert("shubh");

    string text = "abaacadbacad";
    string pattern = "aaca";

    int n = text.size();
    for(int i = 0 ; i+pattern.size() < n ; i++){
        insert(text.substr(i));
    }

    if (checkInTrie(pattern))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}