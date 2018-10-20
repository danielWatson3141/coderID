//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t


int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    srand(time(NULL));
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        cout<<"Case #"<<index<<": ";
        if (rand() % 2)  cout<<"BAD";
        else             cout<<"GOOD";
        cout<<endl;
    }
    
    /*
    int F;
    cin >> F;
    int n;
    vector<long long> v;
    while (cin >> n) {
        v.push_back(n);
    }
    vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */ 
    
    return 0;
}

#endif