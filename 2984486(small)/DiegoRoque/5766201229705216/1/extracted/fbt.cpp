#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int salvo[2000];
typedef vector<int> vi;
typedef vector<vi> vvi;

void minimo(int u,int p,vvi& G){
	int cuenta=0,maxi1=0,maxi2=0;
	for(vi::iterator it=G[u].begin();it!=G[u].end();it++){
		if((*it)==p) continue;
		minimo(*it,u,G);
		if(salvo[*it]>=maxi1){
			maxi2=maxi1;
			maxi1=salvo[*it];
		}	
		else if(salvo[*it]>=maxi2){
			maxi2=salvo[*it];
		}
		cuenta++;
	}	
	if(cuenta==0 or cuenta==1){salvo[u]=1; return;}
	salvo[u]=maxi1+maxi2+1;

}

int main(){
	int N,T,t=0,a,b;
	cin >> T;
	while(T--){
		t++;
		printf("Case #%d: ",t);
		cin >> N;
		vvi G(N+2);
		for(int i=1;i<N;i++){
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int mej=1;
		for(int i=1;i<=N;i++){
			for(int j=0;j<N;j++) salvo[i]=0;
			minimo(i,-1,G);
			mej=max(mej,salvo[i]);
		}
		printf("%d\n",N-mej);
	}
}
