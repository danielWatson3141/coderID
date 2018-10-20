#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MIN(a,b) if(b<a)a=b
#define CH getchar()
int T,n,L,i,j,k,ANS,res,ttt=0;
int f[1001][1001],g[1001][1010],d[10001];
long long sum[10001],ans[10001];
char ch;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&L);
		for (i=1;i<=n;i++){
			for (ch=CH;ch!='0'&&ch!='1';ch=CH); j=1;
			f[i][j]=ch-'0';
			for (j++;j<=L;j++) f[i][j]=CH-'0';
		}
		for (i=1;i<=n;i++){
			for (ch=CH;ch!='0'&&ch!='1';ch=CH); j=1;
			g[i][j]=ch-'0';
			for (j++;j<=L;j++) g[i][j]=CH-'0';
		}
		for (i=1;i<=n;i++){
			sum[i]=0;
			for (j=1;j<=L;j++){
				sum[i]=sum[i]*2+g[i][j];
			}
		}
		sort(sum+1,sum+1+n);
	//	printf("sum:");
	//	for (i=1;i<=n;i++) printf("%d ",sum[i]); printf("\n");
		ANS=1000;
		for (i=1;i<=n;i++){
			res=0;
			for (j=1;j<=L;j++) if(g[i][j]!=f[1][j]) d[j]=1,res++;else d[j]=0;
		//	for (j=1;j<=L;j++) printf("%d ",d[j]); printf("---\n");
			for (j=1;j<=n;j++){
				ans[j]=0;
				for (k=1;k<=L;k++){
					ans[j]=ans[j]*2+f[j][k]^d[k];
				}
			}
			sort(ans+1,ans+1+n);
		//	for (j=1;j<=n;j++) printf("%d ",ans[j]); printf("---\n");
			for (j=1;j<=n;j++) if(sum[j]!=ans[j]) break;
			if(j>n){
			//	printf("hehe\n");
				MIN(ANS,res);
			}
		}
		printf("Case #%d: ",++ttt);
		if(ANS!=1000) printf("%d\n",ANS);
		else printf("NOT POSSIBLE\n");
	//	printf("f:\n");
	//	for (i=1;i<=n;i++) {for (j=1;j<=L;j++) printf("%d",f[i][j]); printf("\n");} 
		
	}
//	system("pause");
}
