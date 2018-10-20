#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
vector<vector<int> > tree;
using namespace std;
int count(int p,int n){
	int cnt=1;//self
	rep(i,tree[n].size()){
		if(tree[n][i]==p) continue;
		else cnt+=count(n,tree[n][i]);
	}
	return cnt;
}


int dfs(int p,int n){
	// cout<<p<< ":"<<n<<endl;
	int t=tree[n].size()-(p>=0?1:0);//字节点个数
	int cnt=0;
	rep(i,tree[n].size()){
		if(tree[n][i]==p) continue;
		else{ 
			if(t==1)
				cnt+=count(n,tree[n][i]);
			else cnt+=dfs(n,tree[n][i]);
		}
	}
	return cnt;
}


int main(){
	int cases;cin>>cases;	
	for(int caseI=1;caseI<=cases;caseI++){
		int N;
		cin>>N;
		tree.clear();
		// tree.resize(0);
		rep(i,N) tree.push_back(vector<int>());
		// tree[N-1].size();
		// tree.resize(N);
		rep(i,N-1){
			// cout<<i<<endl;
			int a,b;
			cin>>a>>b;a-=1;b-=1;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		int m=999999;
		rep(i,N){
			// cout<<i<<":";
			int s=dfs(-1,i);
			// cout<<s<<endl;
			m=min(s,m);	
		}
		printf("Case #%d: %d\n",caseI,m);
	}
	return 0;
}
