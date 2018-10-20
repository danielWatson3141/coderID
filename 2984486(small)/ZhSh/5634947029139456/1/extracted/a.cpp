#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef unsigned long long ull;

const int INF = 999;

bool check(vector<ull> outlets, vector<ull> devices, ull switches)
{
    REP(i,outlets.size())
    {
        outlets[i] = outlets[i] ^ switches;
    }
    sort(devices.begin(), devices.end());
    sort(outlets.begin(), outlets.end());
    
    REP(i,outlets.size())
    {
        if (outlets[i] != devices[i])
            return false;
    }
    return true;
}

int numOfOnes(ull n)
{
    int res = 0;
    for (int i = 0; i < 8 * sizeof(n); ++i)
    {
        if (n & (1l << i))
            res++;
    }
    return res;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        cout << "Case #" << csIx << ": ";
        
        int N, L;
        cin >> N >> L;
        vector<ull> outlets(N);
        REP(i,N)
        {
            string s;
            cin >> s;
            ull outlet = 0;
            REP(j,L)
            {
                if (s[L - 1 - j] == '1')
                {
                    outlet |= (1l << j);
                }
            }
            outlets[i] = outlet;
        }
        vector<ull> devices(N);
        REP(i,N)
        {
            string s;
            cin >> s;
            ull device = 0;
            REP(j,L)
            {
                if (s[L - 1 - j] == '1')
                {
                    device |= (1l << j);
                }
            }
            devices[i] = device;
        }
        
        int res = INF;
        
        
        for (int candIx = 0; candIx < N; ++candIx)
        {
            ull cand = outlets[candIx];
            ull device = devices[0];
            ull switches = cand ^ device;
            
            int numOfSwitches = numOfOnes(switches);
            if (check(outlets, devices, switches))
            {
                res = min(res, numOfSwitches);
            }
        }
        
        if (res == INF)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << res << endl;
    }
    
    return 0;
}
