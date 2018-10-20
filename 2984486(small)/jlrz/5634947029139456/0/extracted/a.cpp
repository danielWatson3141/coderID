#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <memory>
#include <cassert>
#include <set>

using namespace std;

#define MAPITR(a,b) map<a,b>::iterator
#define LISTITR(a)  list<a>::iterator

#define ITER(itr,a) for( itr = (a).begin(); itr != (a).end(); ++itr )
#define ITERNI(itr,a)   for( itr = (a).begin(); itr != (a).end();  )
#define FORI(i,a,b) for( int i(a), _b(b); i < _b; ++i )
#define FORD(i,a,b) for( int i(a), _b(b); i > _b; --i )
#define FORLE(i,a,b)    for( int i(a), _b(b); i <= _b; ++i )
#define FORGE(i,a,b)    for( int i(a), _b(b); i >= _b; --i )

typedef list<bool> lb;
typedef list<char> lc;
typedef list<int> li;
typedef list<double> ld;
typedef list<string> ls;

typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<long long> vll;


long long process_flow(char* flow, int length)
{
    long long ret = 0;

    FORI(i, 0, length)
    {
        switch (flow[i])
        {
        case '0':
            break;
        case '1':
            ret += 1;
            break;
        default:
            assert(0);
        }

        ret <<= 1;
    }

    ret >>= 1;

    return ret;
}

int find_best(const vll& devices, vll& outlets, int depth, int flipValue, int maxDepth)
{

    bool done = true;
    for (const auto& o : outlets)
    {
        if (!binary_search(devices.begin(), devices.end(), o))
        {
            done = false;
            break;
        }
    }

    if (done)
        return depth;
    //if (depth == maxDepth - 1)
    //    return -1;

    //auto outletsCpy = vll(outlets.size());
    //int result = -1, curr;
    //while (flipValue < (1 << maxDepth))
    //{
    //    flipValue += 1;
    //    FORI(i, 0, outlets.size())
    //    {
    //        outletsCpy[i] = (outlets[i] & ~flipValue) | ((outlets[i] ^ flipValue) & flipValue);
    //    }

    //    curr = find_best(devices, outlets, depth + 1, flipValue, maxDepth);
    //}


    auto outletsCpy = vll(outlets.size());
    int result = -1, curr;
    map<int, vi> resultsMap;
    for (long long flipVal = 1; flipVal < ((long long)1 << maxDepth); ++flipVal)
    {
        FORI(i, 0, outlets.size())
        {
            outletsCpy[i] = (outlets[i] & ~flipVal) | ((outlets[i] ^ flipVal) & flipVal);
        }

        bool good = true;
        set<long long> found;
        for (const auto& o : outletsCpy)
        {
            if (!binary_search(devices.begin(), devices.end(), o) || found.find(o) != found.end())
            {
                good = false;
                break;
            }

            found.insert(o);
        }

        if (good)
        {
            int numFlips = 0;
            long long tmp = flipVal;
            while (tmp)
            {
                numFlips += tmp & 1;
                tmp >>= 1;
            }

            if (result < 0 || result > numFlips)
            {
                result = numFlips;
            }
        }
    }

    return result;
}

void process()
{
    int numDevs, length;

    cin >> numDevs;
    cin >> length;

    char line[64];
    cin.getline(line, 64);

    auto outlets = vll(numDevs);

    for (auto &o:outlets)
    {
        cin.read(line, length + 1);
        o = process_flow(line, length);
    }

    auto devices = vll(numDevs);

    for (auto &d : devices)
    {
        cin.read(line, length + 1);
        d = process_flow(line, length);
    }

    sort(devices.begin(), devices.end());

    int result = find_best(devices, outlets, 0, 0, length);

    if (result < 0)
        cout << "NOT POSSIBLE";
    else
        cout << result;
}

int main()
{
    int nCases;
    cin >> nCases;

    FORLE(i, 1, nCases)
    {
        cout << "Case #" << i << ": ";

        process();

        cout << endl;
    }

    return 0;
}