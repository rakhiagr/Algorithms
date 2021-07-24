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

void lpsArray(vector<int>& lps, string a){
    int prefix = 0;
    int n = lps.size();

    lps[0] = 0;

    int i = 1;
    while(i < n){
        if(a[i] == a[prefix]){
            prefix++;
            lps[i] = prefix;
            i++;
        }
        else{
            if(prefix != 0){
                prefix = lps[prefix-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int32_t main()
{
    string str = "ABAABCXABCXABXA";
    string a = "ABCXABX";
    vector<int> lps(a.size(), 0);

    lpsArray(lps, a);

    for(int i : lps)
        cout<<i<<" ";
    cout<<endl;

    int n = str.size();
    int i = 0, j = 0;

    while(i < n){
        if(j == a.size()){
            cout<<"Found pattern at index : "<<(i-j)<<endl;
            j = lps[j-1];
            continue;
        }
        
        if(a[j] == str[i]){
            j++, i++;
        }
        else{
            if(j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
}