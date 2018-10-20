#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string.h>

using namespace std ;
#define MAX 200
string outlet1[MAX] ;
string outlet2[MAX] ;
#define INF 1000000
int n,L ;
int ans  ;
int dfs(int pos,int vis[],vector<int> &index){
		if(pos==n+1){
				ans = min(ans,(int)index.size()) ;
				return 0 ;
		}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		string buffer =outlet2[i] ;
		for(int j=0;j<index.size();j++){
			
			if(outlet2[i][index[j]]=='0'){
				buffer[index[j]]='1';
			}
			else{
				buffer[index[j]]='0' ;
			}
		}
		if(!outlet1[pos].compare(buffer)){
			vis[i]=1 ;
			dfs(pos+1,vis,index) ;
			//vis[i]=0 ;
			
		}
		}
	}
}



int dfs_main(){
	int vis[MAX] ;
	memset(vis,0,sizeof(vis)) ;
	for(int j=1;j<=n;j++){
		vector<int> index ;
		for(int k=0;k<L;k++){
				if(outlet1[1][k]!=outlet2[j][k])
					index.push_back(k) ;
			}
		vis[j]=1 ;
		dfs(2,vis,index) ;
		for(int k=1;k<=n;k++)
			vis[k]=0 ;
		}
	}





int read_inp(){
	scanf("%d",&n) ;
	scanf("%d",&L) ;
	for(int i=1;i<=n;i++){
		cin>>outlet1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>outlet2[i];
	}
}

int main(){
	FILE *fp = freopen("1R.in","r",stdin) ;
	FILE *fp1 = freopen("1R.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
	ans= INF ;
	read_inp() ;
	dfs_main() ;
	printf("Case #%d: ",i) ;
	if(ans!=INF)
		cout<<ans<<endl ;
	else
		cout<<"NOT POSSIBLE"<<endl ;
	}
}
