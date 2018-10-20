#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
#define pb(x) push_back(x) 
#define FF first
#define SS second
vector<int> adj[1001];
int del[1001],have[1001];
void dfs(int v,int p){
	vector<int> ch;
	vector<pair<int,int> > al;
	int delt=0,havet=0;
	for(vector<int>::iterator it=adj[v].begin();it!=adj[v].end();it++){
		int c=*it;
		if(c==p) continue;
		dfs(c,v);
		ch.pb(c);
		delt+=del[c];
		havet+=have[c];
		al.pb(make_pair(have[c],del[c]));
	}
	del[v]=delt+1;
	if(ch.size()==0){		
		have[v]=0;
	}else if(ch.size()==1){
		have[v]=delt;
	}else if(ch.size()==2){
		have[v]=havet;			
	} else {
		int choice=100000;
		for(int i=0;i<al.size();i++){
			for(int j=i+1;j<al.size();j++){
				int cost=al[i].FF+al[j].FF;
				cost+=delt-al[i].SS-al[j].SS;	
				choice=min(choice,cost);
			}
		}
		have[v]=choice;	
	} 
}

void solve(){
	int n;
	scanf("%d",&n);
	//puts("inside");
	for(int i=0;i<1001;i++) adj[i].clear();
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	//puts("read");
	int ans=10000000;
	for(int i=0;i<n;i++){
		memset(have,0,sizeof(have));
		memset(del,0,sizeof(del));
		dfs(i,-1);
		//printf("%d %d\n",i,have[i]);
		ans=min(ans,have[i]);
	}
	printf("%d\n",ans);
}

int main(){
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		printf("Case #%d: ",T);
		solve();
	}
}
