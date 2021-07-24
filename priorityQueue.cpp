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

vector<int> pq = {-1};
int n;

int getMax(){
    return pq[1];
}

int parentElement(int i)
{
    return i >> 1;
}
int leftChild(int i)
{
    return i << 1;
}
int rightChild(int i)
{
    return ((i << 1) + 1);
}

void shiftUp(int i)
{
    if (i > n || i == 1)
        return;

    if (pq[i] > pq[parentElement(i)])
        swap(pq[i], pq[parentElement(i)]);
    shiftUp(parentElement(i));
}

void insertItem(int val)
{
    if (n + 1 == pq.size())
        pq.push_back(0);

    pq[++n] = val;
    shiftUp(n);
    return;
}

bool isEmpty()
{
    return n == 0;
}

void shiftDown(int i)
{
    if (i > n)
        return;

    int swapId = i;

    if (leftChild(i) <= n && pq[i] < pq[leftChild(i)])
        swapId = leftChild(i);
    if (rightChild(i) <= n && pq[swapId] < pq[rightChild(i)])
        swapId = rightChild(i);

    if (swapId != i)
    {
        swap(pq[i], pq[swapId]);
        shiftDown(swapId);
    }
    return;
}

bool extractMaximum()
{
    int num = pq[1];
    swap(pq[1], pq[n--]);
    shiftDown(1);
    return num;
}

int32_t main()
{
    insertItem(10);
    insertItem(120);
    insertItem(34);
    insertItem(41);
    insertItem(5);

    for(int i : pq)
        cout<<i<<" ";
    cout<<endl;

    cout << extractMaximum() << endl;
    cout << getMax() << endl;
}