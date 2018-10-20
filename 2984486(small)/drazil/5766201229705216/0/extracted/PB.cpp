#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std ;

int used[1100][1100] ;
vector<int> link[1100] ;
int n ;
struct res
{
	int a, b ;
} ;
res dpt[1100][1100] ;

bool operator<(const res &a, const res &b)
{
	return ((a.b-a.a)>(b.b-b.a)) ;
}

res go(int id, int pre)
{
	if(used[id][pre]==0)
	{
		used[id][pre] = 1 ;
		res out ;
		out.a = 0 ;
		out.b = 1 ;
		vector<res> poss ;
		for(int i=0;i<link[id].size();i++)
		{
			int nid = link[id][i] ;
			if(nid==pre)
				continue ;
			res r = go(nid,id) ;
			out.b += r.b ;
			poss.push_back(r) ; 
		}
		if(poss.size()==1)
			out.a = poss[0].b ;
		else if(poss.size()>=2)
		{
			sort(poss.begin(), poss.end()) ;
			out.a = poss[0].a+poss[1].a ;
			for(int i=2;i<poss.size();i++)
				out.a += poss[i].b ;
		}
			
		dpt[id][pre] = out ;
	}
	
	return dpt[id][pre] ;
}

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		for(int i=0;i<1100;i++)
			link[i].clear() ;
		cin >> n ;
		memset(used,0,sizeof(used)) ;
		for(int i=1;i<n;i++)
		{
			int a, b ;
			cin >> a >> b ;
			link[a].push_back(b) ;
			link[b].push_back(a) ;
		}
		int ans = n ;
		for(int i=1;i<=n;i++)
			ans = min(ans, go(i,0).a) ;
		printf("Case #%d: %d\n",c,ans) ;
	}
	
	return 0 ;
}
