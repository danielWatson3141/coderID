#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

#define INF 1000000000

#define N 1111

vector<int> edge[N];

int visit[N];

int saiki(int pos){
	
	if(visit[pos]==1)return -1;
	visit[pos]=1;
	
	vector<int> ret;
	rep(i,edge[pos].size()){
		int val = saiki(edge[pos][i]);
		
		if(val!=-1)ret.push_back(val);
	}
	
	sort(ret.begin(),ret.end());
	reverse(ret.begin(),ret.end());
	
	int ans = 0;
	if(ret.size()>=2){
		rep(i,2)ans+=ret[i];
	}
	
	return ans+1;
}

int main(){
	int T;
	cin>>T;
	
	rep(t,T){
		rep(i,N)edge[i].clear();
		int n;
		cin>>n;
		rep(i,n-1){
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		
		int ans = INF;
		reps(i,1,n+1){
			rep(i,N)visit[i]=0;
			ans = min(ans,n-saiki(i));
		}
		
		printf("Case #%d: ",t+1);
		printf("%d\n",ans);
	}
}


/*
1
7
4 5
4 2
1 2
3 1
6 4
3 7

*/