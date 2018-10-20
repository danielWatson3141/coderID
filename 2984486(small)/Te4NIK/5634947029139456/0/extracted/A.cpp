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

int T,n,l;
vector <int> a,b,c;

int parse()
{
	int t=0;
	char c;
	forn(j,l)
    {
    	cin >>c;
    	if(c=='1')
    		t+=1<<(l-j-1);
    }
    return t;
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

    cin >>T;
    forn(I,T)
    {
    	a.clear();
    	b.clear();

    	scanf("%d %d\n",&n,&l);
    	forn(i,n)
    		a.pb(parse());
    	scanf("\n");
    	forn(i,n)
    		b.pb(parse());
    	sort(b.begin(),b.end());

    	int ans=999999;
    	for(int i=0; i<(1<<l); i++)
    	{
    		c.clear();
    		forn(j,n)
    			c.pb(a[j]^i);
    		sort(c.begin(),c.end());
    		
    		bool can=1;
    		forn(j,n)
    			if(c[j]!=b[j])
    				can=0;
    		if(can)
    		{
    			int z=i,tans=0;
    			while(z>0)
    			{
    				if(z%2)
    					tans++;
    				z/=2;
    			}
    			ans=min(ans,tans);
    		}
    	}

    	cout <<"Case #"<<I+1<<": ";
    	if(ans==999999)
    		cout <<"NOT POSSIBLE";
    	else
    		cout <<ans;
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