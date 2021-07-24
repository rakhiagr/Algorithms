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

#define int long long int
int pp = 100000000;
int p = 31;
using namespace std;

int getPower(int a, int b)
{
    int value = 1;
    while (b)
    {
        if (b & 111)
        {
            value *= a;
            value %= pp;
        }
        a *= a;
        b /= 2;
        a %= pp;
    }
    return value;
}

int findInversePower(int a)
{
    return getPower(a, p - 2);
}

int hashFunction(string s)
{
    int res = 0;
    int thePower = 1;
    for (int i = 0; i < s.size(); i++)
    {
        res += (thePower * (s[i] - 'a' + 1));
        res %= pp;
        thePower *= p;
        thePower %= pp;
    }
    return res;
}

int32_t main()
{
    string text = "abab", pattern = "ab";
    int pattern_hash = hashFunction(pattern);
    int n = text.size();
    int val = hashFunction(text.substr(0, pattern.size()));

    if (val == pattern_hash)
        cout << 0 << endl;

    for (int i = 1; i + pattern.size() <= n; i++)
    {
        int newHash = val;
        newHash = (newHash - (text[i - 1] - 'a' + 1) + pp) % pp;

        newHash *= findInversePower(p);
        newHash %= pp;

        newHash = newHash + (text[i + pattern.size() - 1] - 'a' + 1) * getPower(p, pattern.size() - 1);
        newHash %= pp;
        if (pattern_hash == newHash)
            cout << i << endl;

        val = newHash;
    }
}