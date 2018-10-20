#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,i,j,k,x,y,c=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		char in[200];
		string A[200],B[200],C[200];
		for(i=0;i<n;i++){
			scanf("%s",in);
			A[i]=string(in);
		}
		
		for(i=0;i<n;i++){
			scanf("%s",in);
			B[i]=string(in);
		}
		/*for(i=0;i<n;i++){
			puts(A[i].c_str());
		}*/
		int flag=0,ans;
		for(i=0;i<n;i++){
			set<string> bst;
			int check[200]={0},add=0;
			for(j=0;j<m;j++){
				if(A[i][j]!=B[0][j])
					check[j]=1,add++;
			}
			//puts(A[i].c_str());
			//printf("%d...%d,,,",i,add);
			for(j=0;j<n;j++){
				C[j]=A[j];
				for(k=0;k<m;k++){
					if(check[k]){
						if(C[j][k]=='1') C[j][k]='0';
						else C[j][k]='1';
					}
				}
				bst.insert(string(C[j]));
			}
			int tmp=1;
			for(j=0;j<n;j++){
				set<string>::iterator it;
				it=bst.find(string(B[j]));
				if(it==bst.end()){
					tmp=0;
					break;
				}
				bst.erase(it);
			}
			if(tmp && (flag==0 || add<ans) ){
				ans=add;
				flag=1;
			}
		}
		if(flag==0) printf("Case #%d: NOT POSSIBLE\n",++c);
		else printf("Case #%d: %d\n",++c,ans);
	}
}