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

int T,n,l,r,ans,tans;
vector <int> g[1010];

int u[1010];
vector <PII> son[1010];
int dfs(int ver)
{
	u[ver]=1;
	int t=0;
	forn(i,g[ver].size())
		if(!u[g[ver][i]])
		{
			t++;
			int kol=dfs(g[ver][i]);	
			son[ver].pb(mp(-1*kol,g[ver][i]));
		}
	return t;
}

void dfs2(int ver)
{
	tans--;
	if(son[ver].size()<2)
		return;
	forn(i,2)
		dfs2(son[ver][i].y);	
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
    	forn(i,1010)
    		g[i].clear();
    	cin >>n;
    	forn(i,n-1)
    	{
    		cin >>l>>r;
    		l--,r--;
    		g[l].pb(r);
    		g[r].pb(l);
    	}
    	
    	ans=999999;
    	forn(i,n)
    	{
    		memset(u,0,sizeof(u));
    		forn(j,1010)
    			son[j].clear();
    		
    		dfs(i);
    		forn(j,n)
    			sort(son[j].begin(),son[j].end());
    			
    		tans=n;
    		dfs2(i);
    		ans=min(ans,tans);
    	}
    	cout <<"Case #"<<I+1<<": "<<ans<<endl;
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