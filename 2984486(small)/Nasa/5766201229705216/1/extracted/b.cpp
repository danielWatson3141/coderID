#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define MAX 1001

int n,k[MAX][MAX],kc[MAX],lookup[MAX][MAX];

int compute(int parent, int i){
	int mx=1;
	if (parent==-1 || lookup[parent][i]==-1){
		if (kc[i]>1+(parent==-1?0:1)){
			int c=0,d=0;
			for (int j=0; j<kc[i]; j++){ if (k[i][j]==parent) continue;
				int val=compute(i,k[i][j]);
				if (val>=c){ d=c; c=val; } else if (val>=d){ d=val; }
			}
			if (d>=1 && mx<c+d+1) mx=c+d+1;
		}
		if (parent>-1){
			lookup[parent][i]=mx; //cout<<parent+1<<"-"<<i+1<<":"<<mx<<endl;
		}
	}
	else mx=lookup[parent][i];
	return mx;
}

int main(){
	int t,u,i,j,a,b;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n;
		for (i=0; i<n; i++) for (j=0; j<n; j++) lookup[i][j]=-1;
		for (i=0; i<n; i++) kc[i]=0;
		for (i=0; i<n-1; i++){ cin>>a>>b; a--; b--; k[a][kc[a]++]=b; k[b][kc[b]++]=a; }
		int mx=0;
		for (i=0; i<n; i++) mx=max(mx,compute(-1,i));
		cout<<"Case #"<<(u+1)<<": "<<n-mx<<endl;
	}
	return 0;
}
