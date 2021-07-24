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

long long int hashFunction(string str){
    long long int prime = 31, m = 1e9 + 7;
    long long int power = 1;
    long long int hashValue = 0;

    for(int i = 0 ; i < str.size() ; i++){
        hashValue += power * (str[i]-'a' + 1);
        power *= prime;
        power %= m;
        hashValue %= m;
    }
    return hashValue;
}


int32_t main()
{
    string str = "ababab";
    cout<<hashFunction(str)<<endl;
}