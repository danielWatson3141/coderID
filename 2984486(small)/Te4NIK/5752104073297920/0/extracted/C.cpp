#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>
#include <fstream>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

#define getb(x,y) (x&(1<<y))
#define setb(x,y) (1|(1<<y))
#define unsetb(x,y) (x&(~(1<<y)))

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld EPS = 1e-12;
double __t;

int n=1000;
int g[1010],b[1010];

int random(int l, int r)
{
	return l+rand()%(r-l);
}

void good()
{
	forn(i,n)
		swap(g[i],g[random(i,n)]);
}

void bad()
{
	forn(i,n)
		swap(b[i],b[random(0,n)]);
}

int main()
{
    #ifdef local
        __t = clock();
        #ifndef _with_files
            freopen("z.in", "rt", stdin);
            freopen("z.out", "wt", stdout);
        #endif
    #endif
    #ifdef _with_files
        freopen(TASK".in", "rt", stdin);
        freopen(TASK".out", "wt", stdout);
    #endif

    if(0)
    {
    srand(time(0));
                                                   
    forn(I,50)
    {
    	forn(i,n)
    	{
    		g[i]=i;
    		b[i]=i;
    	}
    	good();
    	bad();
    	int sg=0,sb=0;
    	forn(i,300)
    	{
    		if(g[i]>800)
    			sg++;//=g[i];
    		if(b[i]>800)
    			sb++;//=b[i];
    	}
    	cout <<I<<" - "<<sg<<' '<<sb<<endl;
    }
    return 0;
    }

    int T;
    cin >>T;
    forn(I,T)
    {
    	cin >>n;
    	forn(i,1000)
    		cin >>g[i];
    	int ts=0;
    	forn(i,500)
    		ts+=g[i];
    	
    	cout <<"Case #"<<I+1<<": ";
    	if(ts>250000)
    		cout <<"GOOD";
    	else
    		cout <<"BAD";
    	cout <<endl;
    }
    quit();
}

void quit()
{
    #ifdef LOCAL
        cerr << "\n\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
    #endif
    exit(0);        
}