#include<stdio.h>
int tc,tcn;
int n,m;
char a[160][45];
char b[160][45];
int c[160];
int ans;
int main(){
	int i,j,k,l,tans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		ans=999999999;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%s",a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%s",b[i]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				c[j]=a[0][j]^b[i][j];
			}
			for(j=0;j<n;j++){
				for(k=0;k<m;k++){
					a[j][k]^=c[k];
				}
			}
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					for(l=0;l<m;l++){
						if(a[j][l]!=b[k][l]){
							break;
						}
					}
					if(l==m)break;
				}
				if(k==n)break;
			}
			if(j==n){
				tans=0;
				for(j=0;j<m;j++){
					tans+=c[j];
				}
				if(ans>tans)ans=tans;
			}
			for(j=0;j<n;j++){
				for(k=0;k<m;k++){
					a[j][k]^=c[k];
				}
			}
		}
		if(ans>99999){
			printf("Case #%d: NOT POSSIBLE\n",tc);
		}
		else{
			printf("Case #%d: %d\n",tc,ans);
		}
	}
}