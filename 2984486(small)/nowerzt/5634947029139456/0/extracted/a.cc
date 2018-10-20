#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <numeric>
#include <algorithm>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>

using namespace std;

typedef long long ll;

#define mem(a,b) memset(a,b, sizeof a)
#define SZ(x)	(int)x.size()
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin());it!=(x.end());++it)
#define ERR 1e-7
#define PI (2.0*acos(0))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define rep(i,n,m) for(int i = (int)n,_m=(int)m;i<_m;++i)
#define bj(stat,b) (stat & (1<<b))
#define bc(stat,b) (stat & (~(1<<b)))
#define vi vector<int> 
#define vs vector<string>

template <class T> T Abs(T x) {return x<0?-x:x;}

int N,L;

int
main()
{
	int T;
	scanf("%d\n",&T);
	for(int t=1;t<=T;t++) {
		cin>>N>>L;
		vector<string> src;
		vector<string> dst;
		string tmp;
		rep(i,0,N) {
			cin>>tmp;
			src.pb(tmp);
		}
		rep(i,0,N) {
			cin>>tmp;
			dst.pb(tmp);
		}

		map<vs, int> mark;
		queue<vs > q;
		
		sort(ALL(dst));
		sort(ALL(src));
		q.push(src);
		mark[src]=1;
		
		
		while(!q.empty()) {
			vs u = q.front();
			q.pop();
			int d = mark[u];
			rep(j,0,L) {
				rep(i,0,N) u[i][j]=1-(u[i][j]-'0')+'0';
				sort(ALL(u));
				if(!mark[u]) {
					//rep(i,0,N) cout<<u[i]<<" ";
					//cout<<endl;
					mark[u]=d+1;
					q.push(u);
					//if(u==dst) break;
				}
				rep(i,0,N) u[i][j]=1-(u[i][j]-'0')+'0';
			}
		}

		printf("Case #%d: ", t);

		if(!mark[dst]) cout<<"NOT POSSIBLE"<<endl;
		else cout<<mark[dst]-1<<endl;
	}
}
