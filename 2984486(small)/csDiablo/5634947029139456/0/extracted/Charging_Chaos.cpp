#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define stop exit(0)
#define nc -1
#define eps 1e-10
#define inf 1000000000
#define mod 1000000007
#define mp make_pair

#define fill(array,value) memset(array,value,sizeof(array))
#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)
#define Max(a,b) ( (a>b)?a:b )
#define Min(a,b) ( (a<b)?a:b )
#define pi 3.1415926535897932384626433832
#define iread(var) scanf("%d",&var)
#define dread(var) scanf("%f",&var)
#define lread(var) scanf("%lld",&var)
#define input(name) freopen(name,"r",stdin)
#define output(name) freopen(name,"w",stdout)
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef long long ll;

using namespace std;

int n, l;
vector <string> sw1tch, outlet;

void init()
{
    cin >> n >> l;
    cin.ignore();
    sw1tch.clear();
    outlet.clear();

    string inp;
    f(i,0,n-1)
    {
        cin >> inp; //cout << inp << endl;
        sw1tch.push_back(inp);
    }

    f(i,0,n-1)
    {
        cin >> inp; //cout << inp << endl;
        outlet.push_back(inp);
    }
}

int ok(int bitmask)
{
    set <string> ss;
    vector <string> sw1tches = outlet;
    f(bit,0,l-1)
    {
        if ((bitmask>>bit)&1)
        {
            f(i,0,n-1)
                sw1tches[i][bit] = '0' + ('1'-sw1tches[i][bit]);
        }
    }

    f(i,0,n-1)
    {
//        cout << "bitmask: " << bitmask << " got " << sw1tches[i] << endl;
        ss.insert(sw1tches[i]);
    }

    f(i,0,n-1)
        if (ss.find(sw1tch[i])==ss.end())
            return inf;
    return __builtin_popcount(bitmask);
}

void solve(int testIndex)
{
    string ans[2]={"NOT POSSIBLE","POSSIBLE"};
    int movesNumber = inf;

    for(int i=0; i<(1<<l); i++)
    {
        movesNumber = min(movesNumber, ok(i));
    }

    if (movesNumber==inf)
    {
        printf("Case #%d: NOT POSSIBLE\n",testIndex);
    }
    else
    {
        printf("Case #%d: %d\n",testIndex,movesNumber);
    }
}

int main()
{
//	input("test.txt");
    input("A-small-attempt0.in");
    output("A-small-attempt0.out");

	int numberOfTests = 1;
	cin >> numberOfTests;

	f(i,1,numberOfTests)
	{
		init();
		solve(i);
	}

	return 0;
}
