#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

void display(int row)
{
    cout << ' ' << row;
}

typedef set<unsigned long long> Set;

int matches(const Set& outlets, const Set& devices, unsigned long long s)
{
    int count=0;
    for(auto it=devices.begin();it!=devices.end();++it)
    {
        if (outlets.find(*it ^ s) != outlets.end()) ++count;
    }
    return count;
}


int main(int argc, char* argv[])
{
    int tests;
    cin >> tests;
    typedef multimap<double, int> MyMap;
    MyMap variance;
    for (int test = 0; test < tests; ++test)
    {
        int N;
        cin >> N;
        set<int> ord;
        vector<int> shuf;
        shuf.reserve(N);
        for(int i=0;i<N;++i)
        {
            int v;
            cin >> v;
            ord.insert(v);
            shuf.push_back(v);
        }
        double var=0;
        for(int i=0;i<N;++i)
        {
            auto it = ord.find(shuf[i]);
            int dist = distance(ord.begin(), it)-i;
            //var += dist*dist;
            if (dist != 0) var+=1;
        }
        variance.insert(MyMap::value_type(var, test));
    }

    vector<int> result(tests, 1);
    auto it=variance.begin();
    for (int test = 0; test < tests/2; ++test)
    {
//        cout << "V: " << it->first << ','  << it->second << endl;
        result[it->second]=0;
        ++it;
    }
    for (int test = 0; test < tests; ++test)
    {
        if (result[test]>0) cout << "Case #" << test+1 << ": GOOD" << endl;
        else cout << "Case #" << test+1 << ": BAD" << endl;
    }

    return 0;
}

