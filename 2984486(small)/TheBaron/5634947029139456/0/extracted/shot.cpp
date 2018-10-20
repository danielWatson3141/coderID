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
//    int a=5;
//    cout << (a ^ 1) << endl;

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        cout << "Case #" << test << ": ";
        int N, L;
        cin >> N >> L;
        set<unsigned long long> outlets;
        set<unsigned long long> devices;
        unsigned long long num;
        string item;
        for (int i=0;i<N;++i)
        {
            cin >> item;
            std::bitset<40> tmp(item);
            num = tmp.to_ullong();
            outlets.insert(num);
        }
        for (int i=0;i<N;++i)
        {
            cin >> item;
            std::bitset<40> tmp(item);
            num = tmp.to_ullong();
            devices.insert(num);
        }
        //set<unsigned long long> tries;
        int success=L+1;
        unsigned long long max = pow(2,L);
        for(unsigned long long i=0;i<max;++i)
        {
            if (matches(outlets, devices, i) == N)
            {
                unsigned long long val=i;
                int x=0;
                while(val>0)
                {
                    if(val%2)
                    {
                        ++x;
                    }
                    val >>= 1;
                }
                if (x < success) success=x;
                if (success==1) break;
            }
        }
        if (success > L) cout << "NOT POSSIBLE" << endl;
        else cout << success << endl;
    }
    return 0;
}

