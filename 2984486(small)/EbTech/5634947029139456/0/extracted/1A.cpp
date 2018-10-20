#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int T, N, L;
string str;
ll flow[150], dev[150], cflow[150];

int main()
{
    ios::sync_with_stdio(0);
    //cout << fixed << setprecision(9);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
    	cin >> N >> L;
    	for (int i = 0; i < N; ++i)
    	{
    		cin >> str;
    		flow[i] = 0;
    		for (int j = 0; j < L; ++j)
    		if (str[j] == '1')
    			flow[i] |= 1ll << j;
    	}
    	for (int i = 0; i < N; ++i)
    	{
    		cin >> str;
    		dev[i] = 0;
    		for (int j = 0; j < L; ++j)
    		if (str[j] == '1')
    			dev[i] |= 1ll << j;
    	}
    	sort(dev, dev + N);
    	int best = INF;
    	for (int i = 0; i < N; ++i)
    	{
    		ll control = flow[0] ^ dev[i];
    		for (int j = 0; j < N; ++j)
    			cflow[j] = flow[j] ^ control;
    		sort(cflow, cflow + N);
    		bool good = true;
    		for (int j = 0; j < N; ++j)
    			good &= cflow[j] == dev[j];
    		if (good)
    		{
    			int cand = 0;
    			for (int j = 0; j < L; ++j)
    			if ((control >> j) & 1)
    				++cand;
    			best = min(best, cand);
    		}
    	}
    	cout << "Case #" << z << ": ";
    	if (best == INF)
    		cout << "NOT POSSIBLE" << endl;
    	else
    		cout << best << endl;
    }
}
